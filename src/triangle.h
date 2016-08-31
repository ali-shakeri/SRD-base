#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <fstream>

class Triangle {
public:
  Triangle ();
  Triangle (double, double, double);
  friend std::ostream & operator<< (std::ostream &, Triangle);
private:
  double a;
  double b;
  double c;
};

#endif