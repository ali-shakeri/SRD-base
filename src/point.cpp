#include "point.h"

Point Point::cross_product (Point v) {
  return Point {p_y*v.p_z-p_z*v.p_y, p_z*v.p_x-p_x*v.p_z, p_x*v.p_y-p_y*v.p_x};
}
Point operator* (double lhs, Point rhs) {return Point{lhs*rhs.p_x, lhs*rhs.p_y, lhs*rhs.p_z};}
Point operator* (Point lhs, double rhs) {return Point{lhs.p_x*rhs, lhs.p_y*rhs, lhs.p_z*rhs};}
std::ostream & operator<< (std::ostream &os, Point pt) {os << pt.p_x << " " << pt.p_y << " " << pt.p_z;}
