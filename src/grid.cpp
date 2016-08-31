#include "grid.h"

Grid::Grid (int x, int y, int z, GridType grid_type) : x{x}, y{y}, z{z}, grid_type{grid_type} {}

Point Grid::mean_velocity (int M, bool ghost_flag) {
  Point mean_velocity {0, 0, 0};
  int n = atoms.size();
  if (ghost_flag == true && grid_type == GridType::BOUNDARY) {
    for (auto atom : atoms) mean_velocity += atom.vel();
    return mean_velocity/double(M);
  }
  else {
    for (auto atom : atoms) mean_velocity += atom.vel();
    if (!atoms.empty()) return mean_velocity/double(n);
    else return Point {0, 0, 0};
  }
}

double Grid::temperature () {
  double mean_v {0.0};
  double mean_v2 {0.0};
  double tmp;
  for (auto atom : atoms) {
    tmp = atom.vel().norm();
    mean_v += tmp;
    mean_v2 += tmp*tmp;
  }
  if (!atoms.empty()) {
    mean_v /= double (atoms.size());
    mean_v2 /= double (atoms.size());
    return (mean_v2 - mean_v*mean_v)/3.0;
  }
  else
    return 0.0;
}