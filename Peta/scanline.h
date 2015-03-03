#ifndef _SCANLINE_H
#define _SCANLINE_H
#include <iostream>
#include "garis.h"
#include "pixel.h"
#include "warna.h"
#include "boolean.h"
#include "point.h"

using namespace std;

class Scanline{
	public:
	Scanline();
	Scanline(Garis G1, Garis G2);
	~Scanline();

	boolean isBerpotongan (int x, int y, Garis G);
	void drawScanline (int x0, int y0, int x1, int y1, Garis G1, Garis G2, Warna warna);

	//void setGaris1();
	//void seGaris2();

	private:
	Garis G1;
	Garis G2;


};
#endif