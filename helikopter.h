#ifndef _HELIKOPTER_H
#define _HELIKOPTER_H

#include "garis.h"
#include "buffer.h"
#include "badanHeli.h"
#include "ekorHeli.h"
#include "scanline.h"
#include "bentuk.h"

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
		
		void drawHeli(Buffer buff, int scale);			// menggambar kapal
		void clearHeli(Buffer buff, int scale);			// menghapus kapal
		void drawJatuh(Buffer buff, int scale);
		void clearJatuh(Buffer buff, int scale);
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		badanHeli badan;
		ekorHeli ekor;
		//Garis *G;
		
};

#endif
