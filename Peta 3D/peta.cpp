#include "peta.h"

Peta::Peta(){}
Peta::~Peta(){}
void Peta::definePeta(Point p0){
	Point p1(p0.getX()+0, p0.getY()+0);
	Point p2(p0.getX()+30, p0.getY()+10);
	vector<Point> listp1 = this->bentukPersegi(p1,p2);
	//Polygon pol1();

	Point p1(p0.getX()+20, p0.getY()+0);
	Point p2(p0.getX()+50, p0.getY()+10);
	vector<Point> listp2 = this->bentukPersegi(p1,p2);

	Point p1(p0.getX()+0, p0.getY()+20);
	Point p2(p0.getX()+30, p0.getY()+30);
	vector<Point> listp3 = this->bentukPersegi(p1,p2);

	Point p1(p0.getX()+20, p0.getY()+20);
	Point p2(p0.getX()+50, p0.getY()+30);
	vector<Point> listp4 = this->bentukPersegi(p1,p2);
}
void Peta::drawPeta(){
	
}
void Peta::setPolygon(int i, vector<Point> p){

}
Polygon Peta::getPolygon(int i){

}
int Peta::getNbPolygon(){

}

vector<Point> Peta::bentukPersegi(Point a1, Point a2){
	vector<Point> listp;
	listp.push_back(a1);
	Point b1(a1.getX(), a2.getY());
	Point b1(a2.getX(), a1.getY());
	listp.push_back(b1);
	listp.push_back(a2);
	listp.push_back(b2);
	return listp;
}