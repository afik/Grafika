#include "peta.h"

Peta::Peta(){}
Peta::~Peta(){}
void Peta::definePeta(Point p0){ // p0 merupakan titik asal
	Point point[4][2];
	vector<Point> listp[4];
	Polygon polygon[4];
	int deltaX = 0;
	int deltaY = 0;
	for(int i = 0; i < 4; i+=2){
		point[i][0].setX(p0.getX() + deltaX);
		point[i][0].setY(p0.getY() + deltaY);
		deltaX += 30;
		deltaY += 10;
		point[i][1].setX(p0.getX() + deltaX);
		point[i][1].setY(p0.getY() + deltaY);
		listp[i] = bentukPersegi(point[i][0], point[i][1]);
		deltaX -= 10;
		deltaY -= 10;
		point[i+1][0].setX(p0.getX() + deltaX);
		point[i+1][0].setY(p0.getY() + deltaY);
		deltaX += 30;
		deltaY += 10;
		point[i+1][0].setX(p0.getX() + deltaX);
		point[i+1][0].setY(p0.getY() + deltaY);
		listp[i+1] = bentukPersegi(point[i+1][0], point[i+1][1]);
		deltaY += 20;
	}
	for(int i = 0; i < 4; i++){
		polygon[i].setCentrePolygon(point[i][1]);
		polygon[i].addPoint(listp[i]);
		listPolygon.push_back(polygon[i]);
	}
}
void Peta::drawPeta(Buffer buff){
	for(int i = 0; i < listPolygon.size();i++){
		listPolygon[i].drawPolygon(buff, *Warna::putih());
	}
}
void Peta::drawPeta3D(Buffer buff, int height){
	for(int i = 0; i < listPolygon.size();i++){
		listPolygon[i].drawPolygon3D(buff, height, *Warna::putih());
	}
}
void Peta::setPolygon(vector<Point> p){
	Polygon pol(p[0]);
	pol.addPoint(p);
	listPolygon.push_back(pol);
}
Polygon Peta::getPolygon(int i){
	return listPolygon[i];
}
int Peta::getNbPolygon(){
	return listPolygon.size();
}

vector<Point> Peta::bentukPersegi(Point a1, Point a2){
	vector<Point> listp;
	listp.push_back(a1);
	Point b1(a2.getX()+25, a1.getY());
	Point b2(a1.getX()-25, a1.getY());
	listp.push_back(b1);
	listp.push_back(a2);
	listp.push_back(b2);
	return listp;
}