#ifndef _BENTUK_H
#define _BENTUK_H

#include "buffer.h"
#include "garis.h"

using namespace std;

class Bentuk{
	public:
		Bentuk();
		~Bentuk(){}

		void circle(Point center, int Radius, Buffer buf, Warna w);
		void persegi(Point pojok, int panjang, int lebar);
		void setengah_lingkaran(Point center, int Radius, Buffer buf);
		
	private:
		Warna putih;
		Warna hitam;
};

#endif
