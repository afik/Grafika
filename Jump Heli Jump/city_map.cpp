#include "city_map.h"


using namespace std;

city_map::city_map() {

}

city_map::~city_map() {

}

void city_map::addBuilding(Buffer buf, int height) {

	Point p(800,height);
	b.persegi(p, 100, 500-height, buf, *Warna::putih());
}

Bentuk city_map::getBuilding() {

	return b;
}

void city_map::setBuilding(int offset, Buffer buf, int height) {

	Point p(800-offset,height);
	b.persegi(p, 100, 500-height, buf, *Warna::putih());
}

void city_map::clearBuilding(int offset, Buffer buf, int height) {

	Point p1(800-offset+10, height);
	Point p2(800-offset+10, 500);
	Point p3(900-offset+10, height);
	Point p4(900-offset+10, 500);

	Garis g1(p1, p2);
	Garis g2(p3, p4);
	g1.drawLine(buf, *Warna::hitam()); 
	g2.drawLine(buf, *Warna::hitam());

	Point p5(900-offset+1, height);
	b.persegi(p5, 900-offset+10, 500-height, buf, *Warna::hitam());
}

void city_map::clearAll(Buffer buf, int height) {

	Point p3(0, height);
	b.persegi(p3, 100, 500-height, buf, *Warna::hitam());
}


void city_map::motion(int x, Buffer buf, int height) {

	setBuilding(x, buf, height);
	clearBuilding(x, buf, height);
}
