#include "polygon.h"
#include "point.h"
#include <iostream>

using namespace std;

int main() {

	int x, y;
	Polygon polygon;

	while(!polygon.isStop()) {
		cin >> x;
		cin >> y;
		Point p (x,y);
		polygon.addPoint(p);
		polygon.drawPolygon();
	}

	return 0;
}