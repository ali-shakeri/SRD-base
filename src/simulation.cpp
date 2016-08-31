#include "simulation.h"

#include "boundary.h"
#include "initialize.h"

Simulation::Simulation (const char* name) : writer{name}, N{100000}, Lx{40}, Ly{20}, Lz{3}, temperature{0.001},
                                            a{1}, write_step{10}, timestep{0}, dt{1.0} {

  M = N/(Lx*Ly*Lz);
  domain = Domain{Boundary{0,Lx,BoundaryType::PERIODIC}, Boundary{0,Ly,BoundaryType::PERIODIC}, Boundary{0,Lz,BoundaryType::PERIODIC}};
  colloid = Colloid{Point{10., Ly/2., Lz/2.}, Point{0.0, 0.0, 0.0}, 2.0};
  Initialize init {N, Lx, Ly, Lz};
  init.distribute_atoms (atoms);
  init.set_initial_velocity (atoms, Point{0.1, 0.0, 0.0});
  init.set_initial_temperature (atoms, temperature);
  init.distribute_grids (grids);
}

void Simulation::streaming_step () {
  for (auto &atom : atoms) atom.pos() += atom.vel()*dt;
  colloid.stream(dt);
  colloid.apply_boundary_condition (atoms, dt); //TODO becareful about colloid near the wall!
  domain.apply_boundary_condition (atoms, dt);  //TODO there is bug in boundary condition. checking y direction first, temporarily solves the problem.
}

Point Simulation::shift_atoms () {
  Point rnd_vector {rand.uniform_real(-a/2., a/2.), rand.uniform_real(-a/2., a/2.), rand.uniform_real(-a/2., a/2.)};
  for (auto &atom : atoms) atom.pos() += rnd_vector;
  return rnd_vector;
}

void Simulation::sort_atoms_into_grids () {
  for (auto &grid : grids) grid.clear_atoms();
  for (auto atom : atoms) {
    int i = (atom.pos().x() + a/2.)/a;
    int j = (atom.pos().y() + a/2.)/a;
    int k = (atom.pos().z() + a/2.)/a;
    int index = i + j*(Lx+1) + k*(Lx+1)*(Ly+1);
    grids[index].add_atom(atom);
  }
}

void Simulation::collision_step () {
  for (auto &grid : grids) {
    Point R = rand.random_3d_axis ();
    Point mean_velocity = grid.mean_velocity(M, false);
    for (auto &atom : grid.atoms) {
      //compute velocity of atoms relative to bulk velocity and it's parallel and perpendicular components relative to R
      Point relative_velocity = atom.vel() - mean_velocity;
      Point relative_velocity_parallel = Point{(relative_velocity*R)*R.x(), (relative_velocity*R)*R.y(), (relative_velocity*R)*R.z()};
      Point relative_velocity_perpendicular = relative_velocity - relative_velocity_parallel;
      //TODO generaliztion to arbitrary rotation angle is necessary.
      Point rotated_relative_velocity = relative_velocity_perpendicular.cross_product(R) + relative_velocity_parallel;
      atom.vel() = rotated_relative_velocity + mean_velocity;
    }
  }
}

void Simulation::update_atoms () {
  int i = 0;
  for (auto grid : grids)
    for (auto atom : grid.atoms) {
	atoms[i] = atom;
	++i;
      }
}

void Simulation::shift_atoms_back (Point rnd_vector) {
  for (auto &atom : atoms) atom.pos() -= rnd_vector;
}

void Simulation::thermostat (double target_temperature) {
  Point center_mass_velocity {0.0, 0.0, 0.0};
  for (auto atom : atoms) center_mass_velocity += atom.vel();
  center_mass_velocity /= atoms.size();
  double current_temperature;
  for (auto atom : atoms) current_temperature += (atom.vel() - center_mass_velocity)*(atom.vel() - center_mass_velocity)/3.0;
  current_temperature /= atoms.size();
  double scale = sqrt(target_temperature/current_temperature);
  for (auto &atom : atoms) atom.vel() = atom.vel()*scale;
}

void Simulation::step () {
  streaming_step ();
//   thermostat (temperature);
  Point rnd_vector = shift_atoms ();
  sort_atoms_into_grids ();
  collision_step ();
  update_atoms ();
  shift_atoms_back (rnd_vector);
  
  if (timestep%write_step == 0) writer.write(timestep, atoms, colloid);
  ++timestep;
}