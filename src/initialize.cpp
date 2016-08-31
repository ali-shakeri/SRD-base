#include "initialize.h"

Initialize::Initialize (long n, int lx, int ly, int lz) : N{n}, Lx{lx}, Ly{ly}, Lz{lz} {}

void Initialize::distribute_atoms (std::vector<Atom> &atoms) {
  Point position;
  Point colloid_center {10., Ly/2., Lz/2.};
  for (int i=0; i<N; ++i) {
    position = Point{rand.uniform_real(0,Lx),rand.uniform_real(0,Ly), rand.uniform_real(0,Lz)};
    if ((position-colloid_center)*(position-colloid_center)>2)
      atoms.push_back (Atom{position, Point{rand.normal(0,0.1),rand.normal(0,0.1), rand.normal(0,0.1)}, AtomType::FLUID});
  }
}

void Initialize::set_initial_velocity (std::vector<Atom> &atoms, Point init_vel) {
  Point mean_velocity {0, 0, 0};
  for (auto atom : atoms) mean_velocity += atom.vel();
  for (auto &atom : atoms) atom.vel() -= mean_velocity/double(N);
  for (auto &atom : atoms) atom.vel() += init_vel;
}

void Initialize::set_initial_temperature (std::vector<Atom> &atoms, double target_temperature) {
  Point center_mass_velocity {0.0, 0.0, 0.0};
  for (auto atom : atoms) center_mass_velocity += atom.vel();
  center_mass_velocity /= atoms.size();
  double current_temperature;
  for (auto atom : atoms) current_temperature += (atom.vel() - center_mass_velocity)*(atom.vel() - center_mass_velocity)/3.0;
  current_temperature /= atoms.size();
  double scale = sqrt(target_temperature/current_temperature);
  for (auto &atom : atoms) atom.vel() = atom.vel()*scale;
}

void Initialize::distribute_grids (std::vector<Grid> &grids) {
  for (int k=0; k<=Lz; ++k)
    for (int j=0; j<=Ly; ++j)
      for (int i=0; i<=Lx; ++i) {
	if (j == 0 || j == Ly)
	  grids.push_back (Grid{i, j, k, GridType::BOUNDARY});
	else
	  grids.push_back (Grid{i, j, k, GridType::NORMAL});
      }
}