#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include "point.h"

class Random {
public:
  Random () {}
  int uniform_int (int, int);
  double uniform_real (double, double);
  double normal (double, double);
  Point random_3d_axis ();
private:
  std::default_random_engine generator;
};

#endif