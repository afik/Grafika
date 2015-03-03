<<<<<<< HEAD
#ifndef _PETA_H
#define _PETA_H
#include "buffer.h"
#include "point.h"
#include "garis.h"
#include "warna.h"

class Peta{
	public:
		Peta();
		~Peta();
		void gambarPeta(int y, Buffer buff);
		void pulauSumatra(int y, Buffer buff);
		void pulauJawa(int y, Buffer buff);
		void pulauKalimantan(int y, Buffer buff);
		void pulauSulawesi(int y, Buffer buff);
	private:
		Warna putih;
};

=======
#ifndef _PETA_H
#define _PETA_H
#include "buffer.h"
#include "point.h"
#include "garis.h"
#include "warna.h"

class Peta{
	public:
		Peta();
		~Peta();
		void gambarPeta(int y, Buffer buff);
		Garis* getGarisPulau(int pulauKe, int garisKe); // garis dimulai dari 1, pulau juga
	private:
		void pulauSumatra(int y, Buffer buff);
		void pulauJawa(int y, Buffer buff);
		void pulauKalimantan(int y, Buffer buff);
		void pulauSulawesi(int y, Buffer buff);
		//DATA
		Warna putih;
		Garis petaSumatra[6];
		Garis petaJawa[5];
		Garis petaKalimantan[8];
		Garis petaSulawesi[13];
};

>>>>>>> 89d67ea23653560b473c76e0ad09c051d5706a08
#endif