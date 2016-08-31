#ifndef WRITER_H
#define WRITER_H

#include <fstream>
#include <vector>
#include "atom.h"
#include "grid.h"
#include "colloid.h"

class Writer {
public:
  Writer (const char*);
  void write (int, const std::vector<Atom> &, const Colloid &);
  void write_vtk (int, int, int, const std::vector<Grid> &);
private:
  std::ofstream atomfile;
  std::ofstream vtkfile;
};

#endif