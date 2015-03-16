#ifndef _HELIKOPTER_H
#define _HELIKOPTER_H

#include "garis.h"
#include "buffer.h"
#include "badanHeli.h"
#include "ekorHeli.h"
//#include "scanline.h"
#include "bentuk.h"
#include "baling.h"

class Helikopter{
	public:
		Helikopter();
		~Helikopter();
		
		//setter
		//void setN(int N);
		void setVelocity(int velocity);
		void setPosition(Point position);
		void setP1(Point P1);
		void setP2(Point P2);
		
		//getter
		//int getN();
		int getVelocity();
		Point getPosition();
		Point getAnchorP1();
		Point getAnchorP2();
		
		void drawHeli(Buffer buff, int scale);			// menggambar helikopter
		void clearHeli(Buffer buff, int scale);			// menghapus helikopter
		void pecahHeli(Buffer buff);					// helikopter pecah
		void clearpecahHeli(Buffer buff);					// helikopter pecah
		void moveUp(Buffer buf, int scale, int v);
		void moveDown(Buffer buf, int scale, int v);
		
		Garis allLine[9];
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		badanHeli badan;
		ekorHeli ekor;
		
};

#endif
