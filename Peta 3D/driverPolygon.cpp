#include "polygon.h"
#include <iostream>
using namespace std;

int main() {
	Polygon poly;
	// cout << poly.getCentrePolygon().getY() << endl;
	// cout << poly.getCentrePolygon().getX() << endl;

	Point p(400, 400);
	Polygon poly2(p); 
	cout << poly2.getCentrePolygon().getY() << endl;
	cout << poly2.getCentrePolygon().getX() << endl;

	Polygon poly3(poly2);
	cout << poly3.getCentrePolygon().getY() << endl;
	cout << poly3.getCentrePolygon().getX() << endl;

	Polygon poly4 = poly;	
	cout << poly4.getCentrePolygon().getY() << endl;
	cout << poly4.getCentrePolygon().getX() << endl;

	return 0;
}