#ifndef _KAPAL_H
#define _KAPAL_H

#include "garis.h"
#include "buffer.h"

class Kapal{
	public:
		Kapal();
		~Kapal();
		
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
		
		void drawKapal(Buffer buff);			// menggambar kapal
		void clearKapal(Buffer buff);			// menghapus kapal
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		//Garis *G;
		
};

#endif
