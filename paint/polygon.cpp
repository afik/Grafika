#include "polygon.h"

Polygon::Polygon() {

}

bool Polygon::isClosed() {

	bool closed = false;

	if((vertice.front().getX() == vertice.back().getX()) && (vertice.front().getY() == vertice.back().getY())) {
		closed = true;
	}
	return closed;
}

bool Polygon::isStop() {

	bool stop = false;

	if(vertice.size()>3 && isClosed()) {
		stop = true;
	}
	return stop;
}	

void Polygon::addPoint(Point p) {

	vertice.push_back(p);
}

void Polygon::drawPolygon() {

	Garis line;
	Buffer b;
	Warna w;
	if(vertice.size()!=0){
		for(int i=0; i<vertice.size()-1; i++) {
			line.setPointP1(vertice[i]);
			line.setPointP2(vertice[i+1]);
			line.drawLine(b, w);
		}
	}
}

// void Polygon::closedPolygon(){
// 	Garis line;
// 	Buffer b;
// 	Warna w;

// 	line.setPointP1(vertice.back());
// 	line.setPointP2(vertice.front());
// 	line.drawLine(b, w);
// }