#ifndef _FILL_SCAN_H
#define _FILL_SCAN_H
#include <iostream>
#include "garis.h"
#include "pixel.h"
#include "warna.h"
#include "point.h"

using namespace std;

class fillScan{
	public:
	int GetX(Garis G, int y);

	fillScan();
	void fill(int y0, int y1, Garis G1, Garis G2, Warna warna, Buffer buff);
	void fillPolygon(int x, int y, Warna warna, Buffer buff);
	void fillRect(Point P, int w, int h, Warna warna, Buffer buff);
	void fillRect(int x, int y, int w, int h, Warna warna, Buffer buff);
	void fillPattern(Point P, int h, Warna warna1, Warna warna2, Buffer buff);

//	int numLine;
//	Garis allLine[20];
};
#endif
