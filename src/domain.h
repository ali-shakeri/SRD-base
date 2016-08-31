#ifndef DOMAIN_H
#define DOMAIN_H

#include <vector>
#include "boundary.h"
#include "atom.h"

class Domain {
public:
  Domain () {}
  Domain (Boundary, Boundary, Boundary);
  void apply_boundary_condition (std::vector<Atom> &, double);
private:
  Boundary x_direction, y_direction, z_direction;
};

#endif