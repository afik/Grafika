#ifndef _PARASUT_H
#define _PARASUT_H

#include "garis.h"
#include "bentuk.h"
#include "buffer.h"

class Parasut{
	public:
		Parasut();
		~Parasut();
		
		//setter
		//void setN(int N);
		void setVelocity(int velocity);
		void setPosition(Point position);
		void setRadius(int radius);
		
		//getter
		//int getN();
		int getVelocity();
		int getRadius();
		Point getPosition();
		Point getAnchorP1();
		Point getAnchorP2();
		
		void drawParasut(Buffer buff);			// menggambar parasut
		void clearParasut(Buffer buff);			// menghapus parasut
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan parasut
		int radius;
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal parasut
		Bentuk b;
		
};

#endif

