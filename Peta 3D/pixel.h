#ifndef _PIXEL_H
#define _PIXEL_H
#include <iostream>
#include "point.h"
#include "warna.h"
#include "buffer.h"

using namespace std;

class Pixel{
	public:
		Pixel(){}
		~Pixel(){}
		
		void putPixel(Warna warna,Point posisi, Buffer buf);
		void putPixel(Warna warna,int x, int y, Buffer buf);
		Warna getPixel(Point posisi, Buffer buf);
		Warna getPixel(int x, int y, Buffer buf);
	private:
};

#endif
