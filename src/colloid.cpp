#include "colloid.h"

Colloid::Colloid () {}
Colloid::Colloid (Point center, Point velocity, double radius): center{center}, velocity{velocity}, radius{radius} {}

void Colloid::stream (double dt) {
  center += velocity*dt;
}
void Colloid::apply_boundary_condition (std::vector<Atom> &atoms, double dt) {
  double tmp;
  for (auto &atom : atoms) {
    tmp = (atom.pos()-center)*(atom.pos()-center);
    if (tmp < radius) {
      atom.vel() = -atom.vel();
      atom.pos() += (atom.vel()+velocity)*dt;
    } 
  }
}