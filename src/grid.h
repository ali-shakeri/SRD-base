#ifndef GRID_H
#define GRID_H

#include <vector>
#include "atom.h"

enum class GridType {NORMAL, BOUNDARY};

class Grid {
public:
  Grid () {}
  Grid (int, int, int, GridType);
  int index_x () const {return x;}
  int index_y () const {return y;}
  int index_z () const {return z;}
  GridType type() const {return grid_type;}
  GridType &type() {return grid_type;}
  int num_atoms () const {return atoms.size();}
  void add_atom (Atom atom) {atoms.push_back(atom);}
  void clear_atoms () {atoms.clear();}
  Point mean_velocity (int, bool ghost_flag=true);
  double temperature ();
  std::vector<Atom> atoms;
  double velocity() const {return vel;}
  double & velocity() {return vel;}
private:
  int x, y, z;			// coordinates of center
  GridType grid_type;
  double vel;
};

#endif