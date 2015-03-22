#ifndef _BALOK1TM_H
#define _BALOK1TM_H
#include <iostream>
#include "garis.h"
#include "pixel.h"
#include "warna.h"
#include "point.h"
#include "fill_scan.h"

using namespace std;

class Balok1TM{
	public:
	void drawBalok(Point Pt, Point P, int w, int h, int lebar, Buffer buff, Warna warna); // titik mata diatas bangun, masukan point sisi depan, bangun di bawah
	void drawBalok(Point Pt, int x, int y, int w, int h, int lebar, Buffer buff, Warna warna); // titik mata diatas bangun, masukan x dan y sisi depan, bangun di bawah
	void drawBalokAtas(Point Pt, int x, int y, int w, int h, int lebar, Buffer buff, Warna warna); // titik mata dibawah bangun, bangun diatas
	void clear(Point Pt, int x, int y, int w, int h, int lebar, Buffer buff, Warna warna);
};
#endif
