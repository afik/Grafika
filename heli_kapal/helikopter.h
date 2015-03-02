#ifndef _HELIKOPTER_H
#define _HELIKOPTER_H

#include "garis.h"
#include "buffer.h"
#include "badanHeli.h"
#include "ekorHeli.h"
#include "scanline.h"
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
		
<<<<<<< HEAD:helikopter.h
		void drawHeli(Buffer buff, int scale);			// menggambar kapal
		void clearHeli(Buffer buff, int scale);			// menghapus kapal
		void drawJatuh(Buffer buff, int scale);
		void clearJatuh(Buffer buff, int scale);
=======
		void drawHeli(Buffer buff, int scale);			// menggambar helikopter
		void clearHeli(Buffer buff, int scale);			// menghapus helikopter
		void pecahHeli(Buffer buff);					// helikopter pecah
		void clearpecahHeli(Buffer buff);					// helikopter pecah
>>>>>>> 973abda618a71a10e2d4faa5ab8c27cfd54a7899:heli_kapal/helikopter.h
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		badanHeli badan;
		ekorHeli ekor;
		
};

#endif
