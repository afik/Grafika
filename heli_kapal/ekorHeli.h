#ifndef _ekorHeli_H
#define _ekorHeli_H

#include "garis.h"
#include "buffer.h"

class ekorHeli{
	public:
		ekorHeli();
		~ekorHeli();
		
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
		
		void drawekorHeli(Buffer buff, int v);			// menggambar kapal
		void clearekorHeli(Buffer buff, int v);			// menghapus kapal
<<<<<<< HEAD
		void drawekorJatuh(Buffer buff, int v);
		void clearekorJatuh(Buffer buff, int v);
=======
		void drawPecah(Buffer buff, Point P1, Point P2, int v);
		void clearPecah(Buffer buff, Point P1, Point P2, int v);
>>>>>>> 7aebf755cf033efee414ff4001b0241cdb899c07
		
	private:
		int N;			// jumlah titik/garis
		int velocity;	// kecepatan kapal
		Point P1, P2;	// anchor point (statis)
		Point position;	// posisi awal kapal
		//Garis *G;
		
};

#endif
