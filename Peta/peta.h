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

#endif