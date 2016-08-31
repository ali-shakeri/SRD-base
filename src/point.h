#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
public:
  Point () : p_x{0}, p_y{0}, p_z{0} {}
  Point (double x, double y, double z) : p_x{x}, p_y{y}, p_z{z} {}
  double x() const {return p_x;}
  double y() const {return p_y;}
  double z() const {return p_z;}
  double & x() {return p_x;}
  double & y() {return p_y;}
  double & z() {return p_z;}
  double norm () {return sqrt(p_x*p_x + p_y*p_y + p_z*p_z);}
  Point cross_product (Point);
  Point operator- () {return Point{-p_x, -p_y, -p_z};}
  Point operator+ (Point rhs) {return Point{p_x+rhs.p_x, p_y+rhs.p_y, p_z+rhs.p_z};}
  Point operator- (Point rhs) {return Point{p_x-rhs.p_x, p_y-rhs.p_y, p_z-rhs.p_z};}
  Point operator/ (double rhs) {return Point{p_x/rhs, p_y/rhs, p_z/rhs};}
  Point operator+= (Point rhs) {return Point{p_x+=rhs.p_x, p_y+=rhs.p_y, p_z+=rhs.p_z};}
  Point operator-= (Point rhs) {return Point{p_x-=rhs.p_x, p_y-=rhs.p_y, p_z-=rhs.p_z};}
  Point operator/= (double rhs) {return Point{p_x/=rhs, p_y/=rhs, p_z/=rhs};}
  double operator* (Point rhs) {return p_x*rhs.p_x + p_y*rhs.p_y + p_z*rhs.p_z;}
  friend Point operator* (double, Point);
  friend Point operator* (Point, double);
  friend std::ostream & operator<< (std::ostream &, Point);
private:
  double p_x, p_y, p_z;
};

#endif