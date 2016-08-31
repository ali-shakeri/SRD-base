#ifndef ATOM_H
#define ATOM_H

#include "point.h"

enum class AtomType {FLUID, COLLOID};

class Atom {
public:
  Atom (AtomType);
  Atom (Point, Point, AtomType);
  Point pos() const {return position;}
  Point vel() const {return velocity;}
  Point &pos() {return position;}
  Point &vel() {return velocity;}
  AtomType type() const {return atom_type;}
  double energy() const {return 0.5*velocity*velocity;}
  Point momentum() const {return velocity;}
private:
  Point position, velocity;
  AtomType atom_type;
};

#endif