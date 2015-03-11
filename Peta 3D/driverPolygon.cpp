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

	vector<Point> lp;
	Point p(100, 100);
	Point p2(200, 100);
	Point p3(200, 200);
	Point p4(100, 200);
	lp.push_back(p);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	poly.addPoint(lp);
	cout << poly.jumlahTitikPolygon() << endl;
	Buffer buff;
	poly.drawPolygon(buff);

	return 0;
}