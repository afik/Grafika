#ifndef _badanHeli_H
#define _badanHeli_H

#include "garis.h"
#include "buffer.h"
#include "scanline.h"

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
<<<<<<< HEAD:badanHeli.h
		void drawbadanJatuh(Buffer buff, int scale, int v);			// badan heli jatuh
		void clearbadanJatuh(Buffer buff, int scale, int v);			// hapus heli jatuh
=======
		void drawPecah(Buffer buff, Point P1, Point P2, int v);							// menggambar kapal
		void clearPecah(Buffer buff, Point P1, Point P2, int v);						// menghapus kapal
>>>>>>> 973abda618a71a10e2d4faa5ab8c27cfd54a7899:heli_kapal/badanHeli.h

	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		//Garis *G;
		
};

#endif
