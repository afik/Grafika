#include "peta.h"

Peta::Peta(){}
Peta::~Peta(){}
void Peta::definePeta(Point p0){
	vector<Point> listp[6];
	Polygon polygon[4];
	Point okt11(p0.getX() + 0, p0.getY() + 20);
	Point okt12(p0.getX() + 5, p0.getY() + 15);
	Point okt13(p0.getX() + 20, p0.getY() + 0);
	Point okt14(p0.getX() + 25, p0.getY() + 0);
	Point okt15(p0.getX() + 45, p0.getY() + 15);
	Point okt16(p0.getX() + 40, p0.getY() + 20);
	Point okt17(p0.getX() + 25, p0.getY() + 40);
	Point okt18(p0.getX() + 20, p0.getY() + 40);
	vector<Point> okt1;
	okt1.push_back(okt11);
	okt1.push_back(okt12);
	okt1.push_back(okt13);
	okt1.push_back(okt14);
	okt1.push_back(okt15);
	okt1.push_back(okt16);
	okt1.push_back(okt17);
	okt1.push_back(okt18);
	Point center1(p0.getX() + 11, p0.getY() + 10);
	Polygon pol1(center1);
	pol1.addPoint(okt1);
	listPolygon.push_back(pol1);
	p0.setY(p0.getY() + 40);
	Point okt21(p0.getX() + 0, p0.getY() + 10);
	Point okt22(p0.getX() + 2, p0.getY() + 8);
	Point okt23(p0.getX() + 10, p0.getY() + 0);
	Point okt24(p0.getX() + 12, p0.getY() + 0);
	Point okt25(p0.getX() + 22, p0.getY() + 8);
	Point okt26(p0.getX() + 20, p0.getY() + 10);
	Point okt27(p0.getX() + 12, p0.getY() + 20);
	Point okt28(p0.getX() + 10, p0.getY() + 20);
	vector<Point> okt2;
	okt2.push_back(okt21);
	okt2.push_back(okt22);
	okt2.push_back(okt23);
	okt2.push_back(okt24);
	okt2.push_back(okt25);
	okt2.push_back(okt26);
	okt2.push_back(okt27);
	okt2.push_back(okt28);
	Point center2(p0.getX() + 11, p0.getY() + 10);
	Polygon pol2(center2);
	pol2.addPoint(okt2);
	listPolygon.push_back(pol2);
	p0.setY(p0.getY() + 40);
	Point p11(p0.getX() + 0, p0.getY() + 0);
	Point p12(p0.getX() + 30, p0.getY() + 10);
	listp[0] = bentukPersegi(p11, p12);
	Point p21(p0.getX() + 50, p0.getY() + 0);
	Point p22(p0.getX() + 80, p0.getY() + 10);
	listp[1] = bentukPersegi(p21, p22);
	Point p31(p0.getX() + 0, p0.getY() + 30);
	Point p32(p0.getX() + 30, p0.getY() + 40);
	listp[2] = bentukPersegi(p31, p32);
	Point p41(p0.getX() + 50, p0.getY() + 30);
	Point p42(p0.getX() + 80, p0.getY() + 40);
	listp[3] = bentukPersegi(p41, p42);
	Point center[4];
	for(int i = 0; i < 4; i++){
		center[i].setX((listp[i][0].getX() + listp[i][2].getX())/2);
		center[i].setY((listp[i][0].getY() + listp[i][2].getY())/2);
		polygon[i].setCentrePolygon(center[i]);
		polygon[i].addPoint(listp[i]);
		listPolygon.push_back(polygon[i]);
	}
	// Point p[2];
	// p[0].setX(p0.getX() + deltaX);
	// p[0].setY(p0.getY() + deltaY);
	// p[1].setX(p0.getX() + deltaX);
	// p[1].setY(p0.getY() + deltaY);
	// vector<Point> listpi = bentukPersegi(p[0], p[1]);
	// Polygon pol;
	// pol.addPoint(listpi);
	// listPolygon.push_back(pol);
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
void Peta::setPolygon(Point center, vector<Point> p){
	Polygon pol(center);
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
	Point b1(a2.getX()+25, a1.getY());
	Point b2(a1.getX()-25, a2.getY());
	listp.push_back(a1);
	listp.push_back(b1);
	listp.push_back(a2);
	listp.push_back(b2);
	return listp;
}