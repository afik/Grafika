#ifndef _LINGKARAN_H
#define _LINGKARAN_H
#include <iostream>
#include "garis.h"
#include "pixel.h"
#include "warna.h"
#include "point.h"



using namespace std;

class Lingkaran{
	public:
		Lingkaran();
		~Lingkaran();
		void drawLingkaran(Buffer buf); // titik mata diatas bangun, masukan point sisi depan, bangun di bawah
		void clearLingkaran(Buffer buf);
		void setRadius(int r);
		void setCenter(Point p);
		void setWarna(Warna w);
	

	private:
		int Radius;
		Point center;
		Warna warna;

};
#endif