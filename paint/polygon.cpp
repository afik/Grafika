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

	if (!isAround(p)) {
		cout<<"2"<<endl;
		vertice.push_back(p);	
	}
	else {
		cout<<"3"<<endl;
		vertice.push_back(vertice[0]);
	}
	
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

bool Polygon::isAround(Point p) {

	bool around = false;

	if (vertice.size()!=0) {
		if((p.getX() < vertice[0].getX()+5) && (p.getX() > vertice[0].getX()-5)) {
			if((p.getY() < vertice[0].getY()+5) && (p.getY() > vertice[0].getY()-5)) {
				cout << "1" << endl;	
				around = true;
			}
		}
	}
	return around;
}
// void Polygon::closedPolygon(){
// 	Garis line;
// 	Buffer b;
// 	Warna w;

// 	line.setPointP1(vertice.back());
// 	line.setPointP2(vertice.front());
// 	line.drawLine(b, w);
// }