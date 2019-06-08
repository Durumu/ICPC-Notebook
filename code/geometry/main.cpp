// Jack Graham 2017
// Basic computational geometry library
// Points and vectors in 3D and 2D space, plus various utilities

#include <iostream>
#include <cmath>
#include <vector>

// use eq() instead of == for comparing floating point
#define eq(a, b) (abs(a-b) < EPS)

using namespace std;

typedef double T;
const T EPS = 1e-7;

// PT can represent either a point or a vector
struct PT{
  double x, y;
};

ostream& operator<< (ostream& os, PT p) {
  os << '(' << p.x << ", " << p.y << ", " << p.z << ')';
}

// VECTOR AND POINT UTILITIES

// returns vector pointing from o (origin) to a
PT from(PT o, PT a) {
  return PT{a.x-o.x, a.y-o.y, a.z-o.z};
}

// returns dot (scalar) product of two vectors
inline double dot(PT v, PT w) {
  return v.x*w.x + v.y*w.y + v.z*w.z;
}

// returns cross (vector) product of two vectors
PT cross(PT v, PT w) {
  return PT{v.y*w.z-v.z*w.y, v.z*w.x-v.x*w.z, v.x*w.y-v.y*w.x};
}

// returns magnitude of a vector
inline double mag(PT v) {
  return sqrt(dot(v, v));
}
