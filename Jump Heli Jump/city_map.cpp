#include "city_map.h"


using namespace std;

city_map::city_map() {
	pBuild.setX(1000);
	pBuild.setY(469);
	tempAwan = 1000;
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
	// vector<Point> alas;
	// Point p1(1000-lebarBuilding,500);
	// Point p2(1000,500);
	// Point p3(1025,480);
	// Point p4(1025-lebarBuilding,480);
	// alas.push_back(p1);
	// alas.push_back(p2);
	// alas.push_back(p3);
	// alas.push_back(p4);
	// poly.addPoint(alas);

	// poly.drawPolygon3D(buf,height, *Warna::putih());

	pBuild.setX(1000);
	pBuild.setY(469);
	tempBuild = 1000;
	b.persegiB(pBuild, lebarBuilding, height, buf, *Warna::putih());	
}

Awan city_map::getCloud(){
	return awan;
}

Bentuk city_map::getBuilding() {

	return b;
}
		
void city_map::setBuilding(int offset, Buffer buf, int height) {
	pBuild.setX(1000-offset);
	pBuild.setY(469);
	tempBuild = 1000-offset;
	b.persegiB(pBuild, lebarBuilding, height, buf, *Warna::putih());
}

void city_map::clearCloud(Buffer buf){
	awan.clear(buf);
}

void city_map::clearBuilding(int x,Buffer buf, int height) {
	pBuild.setX(1000-x);
	pBuild.setY(469);
	b.persegiB(pBuild, lebarBuilding, height, buf, *Warna::hitam());

}

void city_map::clearAll(int flag, Buffer buf, int height) {
	if (flag ==1 ) {
		pBuild.setX(posAwan-50);
		pBuild.setY(469);
		b.persegiB(pBuild, lebarBuilding, height, buf, *Warna::hitam());
	}
	else {
		awan.setPosisi(tempAwan,height);
		awan.clear(buf);
	}
}

	
void city_map::motion(int x, Buffer buf, int height) {
	clearBuilding(1000-tempBuild,buf, height);
	setBuilding(x, buf, height);
}

void city_map::playCloud(int x, Buffer buf, int height){
	//Pixel pixel;
	awan.setPosisi(tempAwan,height);
	awan.clear(buf);
	// pixel.putPixel(*Warna::hitam(),awan.getBoundary()[0], awan.getBoundary()[1],buf);	
	// pixel.putPixel(*Warna::hitam(),awan.getBoundary()[0], awan.getBoundary()[2],buf);	
	posAwan = 1000-x;
	tempAwan = posAwan;
	awan.setPosisi(posAwan,height);
	awan.draw(buf);
	// pixel.putPixel(*Warna::kuning(),awan.getBoundary()[0], awan.getBoundary()[1],buf);	
	// pixel.putPixel(*Warna::kuning(),awan.getBoundary()[0], awan.getBoundary()[2],buf);	

}
		