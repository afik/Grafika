#ifndef _PELURU_H
#define _PELURU_H

#include "garis.h"

class Peluru {
	public :
		Peluru(int posisiX, int posisiY);					// ctor
		Peluru();											// ctor default
		~Peluru();											// dtor
		
		void drawPeluru();									// prosedur untuk menggambarkan peluru di titik pusat peluru
		void clearPeluru();									// prosedur untuk menghilangkan gambar peluru dari layar
		void luncurkanPeluru(int posisiAbsisPesawat);		// prosedur untuk meluncurkan peluru, asumsi gerak peluru konstan
		
		// GETTER DAN SETTER TITIK DAN JARI-JARI PELURU
		void setAbsisTitikPusatPeluru (int newAbsis);
		void setOrdinatTitikPusatPeluru (int newOrdinat);
		void setRadianPeluru (int newRadiant);
		int getAbsisTitikPusatPeluru();
		int getOrdinatTitikPusatPeluru();
		int getRadianPeluru();
	private :
		Point titikPusatPeluru;
		int radianPeluru;
		Buffer frameBuffer;
		Warna warnaGarisPeluru;
};

#endif
