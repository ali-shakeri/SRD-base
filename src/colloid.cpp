#include "colloid.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

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

void Colloid::read_geometry (const char *name, std::vector<Triangle> &triangles) {
  std::ifstream input_stream (name);
  std::string str;
  std::string tmp;
  double a, b, c;
  while (getline(input_stream, str)) {
    if (str.find("vertex") != std::string::npos) {
      std::stringstream ss(str);
      ss >> tmp >> a >> b >> c;
      triangles.push_back(Triangle{a,b,c});
    }
  }
}