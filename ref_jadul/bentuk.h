#ifndef _BENTUK_H
#define _BENTUK_H
#include <iostream>
#include "point.h"
#include "warna.h"
#include "buffer.h"
#include "garis.h"
#include "pixel.h"
#include "fill.h"

using namespace std;

class Bentuk{
	public:
		Bentuk();
		~Bentuk(){}

		void circle(Point center, int Radius, Buffer buf, Warna w);
		void persegi(Point pojok, int panjang, int lebar);
		void setengah_lingkaran(Point center, int Radius, Buffer buf);
		
		void hapus_kapal_laut(int dir, int velocity, Buffer buf);
		void kapal_laut(int dir, int velocity, Buffer buf);
		void boom(Buffer buf);
		void hapus_pesawat(int dir, int v, Buffer buf);
		void pesawat(int dir, int velocity, Buffer buf);
		void baling(Point center, Buffer buf);
		void parasut(Point center_p, int radius_p, Buffer buf);
		
	private:
		Warna putih;
		Warna hitam;
};

#endif
