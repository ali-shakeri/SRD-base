#ifndef BOUNDARY_H
#define BOUNDARY_H

enum class BoundaryType {PERIODIC, SLIP, NO_SLIP, THERMAL};

class Boundary {
public:
  Boundary () {}
  Boundary (int, int, BoundaryType);
  BoundaryType type () const {return boundary_type;}
  int high() const {return higher_limit;}
  int low() const {return lower_limit;}
private:
  int lower_limit, higher_limit;
  BoundaryType boundary_type;
};

#endif