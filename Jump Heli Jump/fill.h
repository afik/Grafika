#ifndef _FILL_H
#define _FILL_H
#include <iostream>
#include "point.h"
#include "warna.h"
#include "buffer.h"
#include "garis.h"
#include "pixel.h"
#include "pattern.h"

using namespace std;

class Fill{
	public:
		Fill(){}
		~Fill(){}

		void FloodFill(Point posisi, Warna warnaLama, Warna warna, Buffer buf);
		void FloodFill(int pointx, int pointy, Warna warnaLama, Warna warna, Buffer buf);
		void patternFill(Point start, Warna warnaLama, char flag, Buffer buf);
		void patternFill(int pointx, int pointy, Warna warnaLama, char flag, Buffer buf);
		
	private:
	
};

#endif

