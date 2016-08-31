#include "random.h"
#include <cmath>

int Random::uniform_int (int a, int b) {
  std::uniform_int_distribution<int> distribution (a, b);
  return distribution (generator);
}

double Random::uniform_real (double a, double b) {
  std::uniform_real_distribution<> distribution (a, b);
  return distribution (generator);
}

double Random::normal (double mean, double stdv) {
  std::normal_distribution<> distribution (mean, stdv);
  return distribution (generator);
}

Point Random::random_3d_axis () {
  std::uniform_real_distribution<> distribution (0, 1);
  double r1 = distribution (generator);
  double r2 = distribution (generator);
  double phi = 2*3.141592654*r1;
  double rho = 2*r2 - 1;
  return Point {cos(phi)*sqrt(1-rho*rho), sin(phi)*sqrt(1-rho*rho), rho};
}