#ifndef _HELIKOPTER_H
#define _HELIKOPTER_H

#include "garis.h"
#include "buffer.h"

class Helikopter{
	public:
		Helikopter();
		~Helikopter();
		
		//setter
		//void setN(int N);
		void setVelocity(int velocity);
		void setPosition(Point position);
		
		//getter
		//int getN();
		int getVelocity();
		Point getPosition();
		Point getAnchorP1();
		Point getAnchorP2();
		
		void drawHeli(Buffer buff);			// menggambar kapal
		void clearHeli(Buffer buff);			// menghapus kapal
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		//Garis *G;
		
};

#endif