#include "main.cpp"

// A polygon is a vector of points
typedef vector<PT> Polygon;

// returns area of triangle formed by first 3 points in a polygon
double triangle_area(Polygon& p) {
  return mag(cross(from(p[0], p[1]), from(p[0], p[2]))) / 2;
}

struct compare {
  bool operator() (PT a, PT b) const {
    
  }
}