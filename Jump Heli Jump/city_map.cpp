#include "city_map.h"


using namespace std;

city_map::city_map() {
	pBuild.setX(1000-85);
	pBuild.setY(468);
	
	pPoly.setX(1000-55);
	pPoly.setY(467);

	tempAwan = 1000;

	ukuranX = 1000;
	ukuranY = 600;

	matriks = (int**) malloc (ukuranY*sizeof(int*));
	for (int i = 0; i < ukuranY; ++i){
		matriks[i] = (int*) malloc (ukuranX*sizeof(int));
	}
	for (int i = 0; i < ukuranY; ++i){
		for(int j = 0; j < ukuranX; j++){
			matriks[i][j] = 0;
		}
	}
}

city_map::~city_map() {

}

void city_map::addCloud(Buffer buf, int height){
	posAwan = 1000;
	tempAwan = 1000;
	awan.setPosisi(posAwan,height);
	awan.draw(buf);
}

void city_map::addBuilding(Buffer buf, int height) {
	Pixel pixel;
	fillScan fill;

	fill.fillPattern(pPoly,50, *Warna::biru(), *Warna::kuning(), buf);
	pPoly.setX(1000-85);
	pPoly.setY(467);
	fill.fillPattern(pPoly,height, *Warna::biru(), *Warna::kuning(), buf);
	
	vector<Point> lp;
	Point p(1000-30, 467-20);
	Point p2(1000+25, 467-10);
	Point p3(1000, 467);
	Point p4(1000-55, 467-5);
	lp.push_back(p);
	lp.push_back(p2);
	lp.push_back(p3);
	lp.push_back(p4);
	poly.addPoint(lp);
	poly.drawPolygon3D(buf, 50, *Warna::coklat(), matriks);

	vector<Point> lp2;
	Point p21(1000-60, 467-17);
	Point p22(1000-2, 467-12);
	Point p23(1000-27, 467-2);
	Point p24(1000-85, 467-7);
	lp2.push_back(p21);
	lp2.push_back(p22);
	lp2.push_back(p23);
	lp2.push_back(p24);
	poly2.addPoint(lp2);
	poly2.drawPolygon3D(buf, height, *Warna::coklat(), matriks);


}

Polygon city_map::getPoly(){
	return poly2;
}

Awan city_map::getCloud(){
	return awan;
}

void city_map::clearCloud(Buffer buf){
	awan.clear(buf);
}

void city_map::clearAll(int flag, Buffer buf, int height) {
	fillScan fill;
	if (flag ==1 ) {
		pBuild.setX(pBuild.getX()-10);
		fill.fillRect(pBuild, 130, height+20, *Warna::hitam(), buf);
	}
	else {
		awan.setPosisi(tempAwan,height);
		awan.clear(buf);
	}
}

	
void city_map::motion(int x, Buffer buf, int height) {
	fillScan fill;
	fill.fillRect(pBuild, 130, height+20, *Warna::hitam(), buf);

	pPoly.setX(1000-55-x);
	pPoly.setY(467);
	fill.fillPattern(pPoly,50, *Warna::biru(), *Warna::kuning(), buf);
	pPoly.setX(1000-85-x);
	pPoly.setY(467);
	fill.fillPattern(pPoly,height, *Warna::biru(), *Warna::kuning(), buf);
	
	poly2.moveLeft(x,height,matriks);
	poly.moveLeft(x, 50, matriks);
	poly.drawPolygon3D(buf, 50, *Warna::coklat(), matriks);
	poly2.drawPolygon3D(buf, height, *Warna::coklat(), matriks);
	
	pBuild.setX(1000-85-x);
	pBuild.setY(468);
	
	for (int i = 0; i < ukuranY; ++i){
		for(int j = 0; j < ukuranX; j++){
			matriks[i][j] = 0;
		}
	}
}

void city_map::playCloud(int x, Buffer buf, int height){
	awan.setPosisi(tempAwan,height);
	awan.clear(buf);
	posAwan = 1000-x;
	tempAwan = posAwan;
	awan.setPosisi(posAwan,height);
	awan.draw(buf);
}
		