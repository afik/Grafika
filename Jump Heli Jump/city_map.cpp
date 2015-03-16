#include "city_map.h"


using namespace std;

city_map::city_map() {
	pBuild.setX(1000+26);
	pBuild.setY(467);
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
	Pixel pixel;
	fillScan fill;
	Point p(1025,457);
	poly.setCentrePolygon(p);
	vector<Point> alas;
	Point p1(1000-25,467);
	Point p2(1000,447);
	Point p3(1000+lebarBuilding-22,467);
	Point p4(1000+lebarBuilding-47,447);
	alas.push_back(p1);
	alas.push_back(p2);
	alas.push_back(p3);
	alas.push_back(p4);
	poly.addPoint(alas);

	poly.drawPolygon3D(buf,height, *Warna::putih());
	fill.fillPattern(pBuild,height-10, *Warna::kuning(), *Warna::putih(), buf);
	pixel.putPixel(*Warna::kuning(),poly.getBoundary(height,467)[0], poly.getBoundary(height,467)[1],buf);	
	pixel.putPixel(*Warna::kuning(),poly.getBoundary(height,467)[0], poly.getBoundary(height,467)[2],buf);	

}

Polygon city_map::getPoly(){
	return poly;
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
		fill.fillRect(pBuild, 100, height, *Warna::hitam(), buf);
		poly.clearPolygon(height, buf);
	}
	else {
		awan.setPosisi(tempAwan,height);
		awan.clear(buf);
	}
}

	
void city_map::motion(int x, Buffer buf, int height) {
	fillScan fill;
	Pixel pixel;
	fill.fillRect(pBuild, 100, height, *Warna::hitam(), buf);
	poly.moveLeft(height, buf);
	pBuild.setX(1000+26-x);
	pBuild.setY(467);
	poly.drawPolygon3D(buf, height,*Warna::putih());
	//printf("%d %d %d\n", poly.getBoundary(height,467)[0], poly.getBoundary(height,467)[1], poly.getBoundary(height,467)[2]);
	// pixel.putPixel(*Warna::merah(),poly.getBoundary(height,467)[0], poly.getBoundary(height,467)[1],buf);	
	// pixel.putPixel(*Warna::merah(),poly.getBoundary(height,467)[0], poly.getBoundary(height,467)[2],buf);	
	fill.fillPattern(pBuild,height-10, *Warna::kuning(), *Warna::putih(), buf);
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
		