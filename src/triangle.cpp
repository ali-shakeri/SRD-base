#include "triangle.h"

Triangle::Triangle () {}

Triangle::Triangle (double a, double b, double c) : a{a}, b{b}, c{c} {}

std::ostream & operator<< (std::ostream &os, Triangle tr) {os << tr.a << " " << tr.b << " " << tr.c;}