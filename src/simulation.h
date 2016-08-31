#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "atom.h"
#include "grid.h"
#include "domain.h"
#include "writer.h"
#include "random.h"
#include "colloid.h"

class Simulation {
public:
  Simulation (const char *);
  void step ();
private:
  std::vector<Atom> atoms;
  std::vector<Grid> grids;
  Domain domain;
  Writer writer;
  Random rand;
  Colloid colloid;
  const long N;
  const int Lx;
  const int Ly;
  const int Lz;
  const int a;
  const double dt;
  const double temperature;
  const int write_step;
  long timestep;
  int M;
  void streaming_step ();
  Point shift_atoms ();
  void sort_atoms_into_grids ();
  void collision_step ();
  void update_atoms ();
  void shift_atoms_back (Point);
  void thermostat (double);
};

#endif