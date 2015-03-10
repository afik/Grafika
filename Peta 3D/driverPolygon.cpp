#include "polygon.h"
#include <iostream>
using namespace std;

int main() {
	Polygon poly;
	// cout << poly.getCentrePolygon().getY() << endl;
	// cout << poly.getCentrePolygon().getX() << endl;

	// Point p(400, 400);
	// Polygon poly2(p); 
	// cout << poly2.getCentrePolygon().getY() << endl;
	// cout << poly2.getCentrePolygon().getX() << endl;

	// Polygon poly3(poly2);
	// cout << poly3.getCentrePolygon().getY() << endl;
	// cout << poly3.getCentrePolygon().getX() << endl;

	// Polygon poly4 = poly;	
	// cout << poly4.getCentrePolygon().getY() << endl;
	// cout << poly4.getCentrePolygon().getX() << endl;

	list<Point> lp;
	Point p(100, 150);
	Point p2(102, 152);
	Point p3(103, 153);
	Point p4(104, 154);
	Point p5(105, 155);
	lp.push_back(p);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	lp.push_back(p5);
	poly.addPoint(lp);
	cout << poly.jumlahTitikPolygon() << endl;

	return 0;
}