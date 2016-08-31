#include "writer.h"
#include "utils.h"

Writer::Writer (const char* name) : atomfile {name}, vtkfile {"data/test.vtk"} {}

void Writer::write (int step, const std::vector<Atom> &atoms, const Colloid &colloid) {
  double total_energy{0};
  Point total_momentum{0,0,0};
  for (auto atom : atoms) {
    total_energy += atom.energy();
    total_momentum += atom.momentum();
  }
  
  atomfile << atoms.size()+1 << std::endl;
  atomfile << "#Step: " << step << "   #Energy: " << total_energy/atoms.size();
  atomfile << "   #Momentum: " << total_momentum/atoms.size() << std::endl;
  for (auto atom : atoms) {
    switch (atom.type()) {
      case AtomType::FLUID :
	atomfile << 0 << " ";
	break;
      case AtomType::COLLOID :
	atomfile << 1 << " ";
	break;
    }
    atomfile << atom.pos() << "   " << atom.vel() << std::endl;
  }
  atomfile << 2 << " " << colloid.pos() << "   " << colloid.vel() << std::endl;
}

void Writer::write_vtk (int Lx, int Ly, int Lz, const std::vector<Grid> &grids) {
  std::string s1 = number_to_string (Lx+1);
  std::string s2 = number_to_string (Ly+1);
  std::string s3 = number_to_string (Lz+1);
  std::string s0 = number_to_string ((Lx+1)*(Ly+1)*(Lz+1));
  vtkfile << "# vtk DataFile Version 3.0\n";
  vtkfile << "grid velocities\n";
  vtkfile << "ASCII\n";
  vtkfile << "DATASET STRUCTURED_POINTS\n";
  vtkfile << "DIMENSIONS " + s1 + " " + s2 + " " + s3 + "\n";
  vtkfile << "ORIGIN 0 0 0\n";
  vtkfile << "SPACING 1 1 1\n";
  vtkfile << "POINT_DATA " + s0 + "\n";
  vtkfile << "SCALARS temperature float\n";
  vtkfile << "LOOKUP_TABLE default\n";
  for (int z=0; z<=Lz; ++z)
    for (int y=0; y<=Ly; ++y)
      for (int x=0; x<=Lx; ++x)
	for (auto grid : grids)
	  if (grid.index_x() == x && grid.index_y() == y && grid.index_z() == z)
	    vtkfile << grid.velocity() << std::endl;
}