#ifndef COLLOID_H
#define COLLOID_H

#include <vector>
#include "atom.h"
#include "point.h"
#include "triangle.h"

class Colloid {
public:
  Colloid ();
  Colloid (Point, Point, double);
  Point pos() const {return center;}
  Point vel() const {return velocity;}
  void stream (double);
  void apply_boundary_condition (std::vector<Atom> &, double);
  
  void read_geometry(const char *, std::vector<Triangle> &);
private:
  Point center;
  Point velocity;
  Point force;
  double radius;
  double mass;
};

#endif