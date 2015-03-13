#ifndef _badanHeli_H
#define _badanHeli_H

#include "garis.h"
#include "buffer.h"
//#include "scanline.h"

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
		badanHeli getBadan();
		
		void drawbadanHeli(Buffer buff, int scale, int v);			// menggambar kapal
		void clearbadanHeli(Buffer buff, int scale, int v);			// menghapus kapal
		void drawPecah(Buffer buff, Point P1, Point P2, int v);							// menggambar kapal
		void clearPecah(Buffer buff, Point P1, Point P2, int v);						// menghapus kapal
		void badanHeliUp(Buffer buff, int scale, int v);
		void clearHeliUp(Buffer buff, int scale, int v);

	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		//Garis *G;
		
};

#endif
