#ifndef _AWAN_H
#define _AWAN_H
#include "warna.h"
#include "garis.h"
#include "pixel.h"
#include "point.h"

class Awan{
	public:
		Awan(Buffer buf, int x, int y, int rad);
		~Awan();
		void draw(Buffer buf);
		int* getBoundary();
		Point getPosisi();
		int getRadius();
		void setPosisi(int x, int y);
		void setRadius(int rad);

	private:
		Point pos;
		int jari;
		Point sudut[];

};

#endif
