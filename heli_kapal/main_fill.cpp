#include "fill_scan.h"

int main(){
	fillScan f;
	Warna putih;
	Buffer buff;
	Point p(400,400);
	Point p1(1000,700);
	Warna biru(0,255,255);
	f.fillPolygon(600, 450, putih, buff);
	f.fillRect(p, 100, 200, putih, buff);
	f.fillPattern(p1, 135, putih, biru, buff);
	return 0;
}