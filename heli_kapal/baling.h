#ifndef _BALING_H
#define _BALING_H
#include <iostream>

#include <math.h>
#include "point.h"
#include "warna.h"
#include "buffer.h"
#include "garis.h"
#include "pixel.h"

#define PI 3.14

class Baling{
	public:
		Baling();
		~Baling();
		void circle(int Radius, Buffer buf, Warna w);
		void baling(Buffer buf);
		void rotasiBaling(int sudut, Buffer buf);
		Point getCenter();
		void setCenter(Point _center);
		void clearBaling(int sudut, Buffer buf);
		
		void setRadius(int radius);
		int getRadius();
	private:
		Point rotasiTitik(Point p, int sudut);
		int convertToInt(float f);
		Point center;
		Warna putih;
		Warna hitam;
		int radius;
};

#endif
