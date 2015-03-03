#ifndef _BENTUK_H
#define _BENTUK_H

#include "buffer.h"
#include "garis.h"

class Bentuk{
	public:
		Bentuk();
		~Bentuk();

		void circle(Point center, int Radius, Buffer buf, Warna w);
		void circle(int x, int y, int Radius, Buffer buf, Warna w);
		void setengah_lingkaran(Point center, int Radius, Buffer buf, Warna w);
		void setengah_lingkaran(int x, int y, int Radius, Buffer buf, Warna w);
		void persegi(Point kiriatas, int panjang, int lebar, Buffer buf, Warna w);
		
	private:
		
};

#endif
