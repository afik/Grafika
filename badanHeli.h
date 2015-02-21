#ifndef _badanHeli_H
#define _badanHeli_H

#include "garis.h"
#include "buffer.h"

class badanHeli{
	public:
		badanHeli();
		~badanHeli();
		
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
		
		void drawbadanHeli(Buffer buff, int v);			// menggambar kapal
		void clearbadanHeli(Buffer buff, int v);			// menghapus kapal
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		//Garis *G;
		
};

#endif