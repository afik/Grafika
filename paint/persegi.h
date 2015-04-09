#ifndef _PERSEGI_H
#define _PERSEGI_H
#include <iostream>
#include "garis.h"
#include "pixel.h"
#include "warna.h"
#include "point.h"



using namespace std;

class Persegi{
	public:
		Persegi();
		~Persegi();
		void drawPersegi(Warna warna, Buffer buff); // titik mata diatas bangun, masukan point sisi depan, bangun di bawah
		void clearPersegi(Buffer buff);
		void setPanjang(int p);
		void setLebar(int l);
		void setKiriAtas(Point P);

	private:
		int Panjang;
		int Lebar;
		Point KiriAtas;
};
#endif