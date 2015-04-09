#ifndef _GARIS_H
#define _GARIS_H

#include "point.h"
#include "buffer.h"
#include "warna.h"
#include "pixel.h"
#include <iostream>

using namespace std;

class Garis{
	public:
		Garis();
		Garis(Point P1, Point P2);
		Garis(int x1, int y1, int x2, int y2);
		Garis(const Garis& g);
		Garis& operator=(const Garis& g);
		~Garis();
		
		void setPointP1(Point P1);
		void setPointP2(Point P2);
		Point getPointP1();
		Point getPointP2();
		
		void drawLine(Buffer b, Warna warna);
		void drawLine(Buffer b, Warna warna, int** matriks);

		
	private:
		Point P1;		//titik awal
		Point P2;		//titik akhir
};

#endif
