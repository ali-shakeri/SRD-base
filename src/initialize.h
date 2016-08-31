#ifndef INITIALIZE_H
#define INITIALIZE_H

#include "atom.h"
#include "grid.h"
#include "random.h"

class Initialize {
public:
  Initialize (long, int, int, int);
  void distribute_atoms (std::vector<Atom> &);
  void set_initial_velocity (std::vector<Atom> &, Point);
  void set_initial_temperature (std::vector<Atom> &, double);
  void distribute_grids (std::vector<Grid> &);
private:
  const long N;
  const int Lx;
  const int Ly;
  const int Lz;
  Random rand;
};

#endif