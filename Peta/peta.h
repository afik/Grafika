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
		void gambarPeta(int y, Buffer buff, Warna putih);
		Garis* getGarisPulau(int pulauKe, int garisKe); // garis dimulai dari 1, pulau juga
		Garis* getPetaSumatra();
		Garis* getPetaJawa();
		Garis* getPetaKalimantan();
		Garis* getPetaSulawesi();
		Garis petaSumatra[6];
		Garis petaJawa[5];
		Garis petaKalimantan[8];
		Garis petaSulawesi[13];

	private:
		void pulauSumatra(int y, Buffer buff, Warna putih);
		void pulauJawa(int y, Buffer buff, Warna putih);
		void pulauKalimantan(int y, Buffer buff, Warna putih);
		void pulauSulawesi(int y, Buffer buff, Warna putih);
		//DATA
		
		
};

#endif
