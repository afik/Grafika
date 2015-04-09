#ifndef _POINTER_H
#define _POINTER_H
#include <iostream>
#include "garis.h"
#include "pixel.h"
#include "warna.h"
#include "point.h"


using namespace std;

class Pointer{
	public:
		void drawPointer(Buffer buff); // titik mata diatas bangun, masukan point sisi depan, bangun di bawah
		void clearPointer(Buffer buff);
		void setPosisi(Point P);
		void setPosisi(int x, int y);
		void putPixel(Warna warna, Buffer buff);

	private:
		Point posisi;
};
#endif