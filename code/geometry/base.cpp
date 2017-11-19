// Jack Graham 2017
// Lightweight basic 2D geometry

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// PT can represent either a point or a vector
typedef pair<double, double> PT;

// For the purposes of this library, a polygon is represented
// by a vector of its points, starting from the one with largest X,
// going counterclockwise 
typedef vector<PT> Polygon;

// VECTOR AND POINT UTILITIES

// returns vector pointing from o (origin) to a
PT from(PT o, PT a) {
	return PT(a.first-o.first, a.second-o.second);
}

// returns magnitude of a vector
double mag(PT v) {
	return sqrt(v.first*v.first + v.second*v.second);
}

// returns cross of two vectors
double cross(PT a, PT b) {
	

// returns area of triangle formed by first 3 points in a polygon
double triangle_area(Polygon& p) {
	return mag(cross(from(p.at(0), p.at(1)), from(p.at(0), p.at(2)))) / 2.0;
