<<<<<<< HEAD
#ifndef _LEDAKAN_H
#define _LEDAKAN_H

#define PI 3.14159265

#include "garis.h"
#include <stdio.h>
#include <math.h>

class Ledakan {
	public :
		Ledakan(int posisiX, int posisiY);				// ctor
		Ledakan();										// ctor default
		~Ledakan();										// dtor
		
		void drawLedakan();								// prosedur untuk menggambar ledakan sesaat
		void clearLedakan();							// prosedur untuk menghapus gambar ledakan sesaat
		void meledak();									// prosedur untuk menggambar ledakan secara keseluruhan dari awal sampai akhir
		int absisHasilTrigonometri(double degrees);		// fungsi untuk menghitung proyeksi radius ledakan pada sumbu X dengan sudut degrees
		int ordinatHasilTrigonometri(double degrees);	// fungsi untuk menghitung proyeksi radius ledakan pada sumbu Y dengan sudut degrees
		
		// GETTER DAN SETTER TITIK LEDAKAN
		void setAbsisTitikPusatLedakan (int newAbsis);
		void setOrdinatTitikPusatLedakan (int newOrdinat);
		void setRadiusLedakan (int newRadius);
		int getAbsisTitikPusatLedakan();
		int getOrdinatTitikPusatLedakan();
		int getRadiusLedakan ();
	private :
		Point titikPusatLedakan;
		int radiusLedakan;
		Buffer frameBuffer;
};

#endif
=======
#ifndef _LEDAKAN_H
#define _LEDAKAN_H

#define PIx 3.14159265

#include "garis.h"
#include <stdio.h>
#include <math.h>

class Ledakan {
	public :
		Ledakan(int posisiX, int posisiY);				// ctor
		Ledakan();										// ctor default
		~Ledakan();										// dtor
		
		void drawLedakan();								// prosedur untuk menggambar ledakan sesaat
		void clearLedakan();							// prosedur untuk menghapus gambar ledakan sesaat
		void meledak();									// prosedur untuk menggambar ledakan secara keseluruhan dari awal sampai akhir
		int absisHasilTrigonometri(double degrees);		// fungsi untuk menghitung proyeksi radius ledakan pada sumbu X dengan sudut degrees
		int ordinatHasilTrigonometri(double degrees);	// fungsi untuk menghitung proyeksi radius ledakan pada sumbu Y dengan sudut degrees
		
		// GETTER DAN SETTER TITIK LEDAKAN
		void setAbsisTitikPusatLedakan (int newAbsis);
		void setOrdinatTitikPusatLedakan (int newOrdinat);
		void setRadiusLedakan (int newRadius);
		int getAbsisTitikPusatLedakan();
		int getOrdinatTitikPusatLedakan();
		int getRadiusLedakan ();
	private :
		Point titikPusatLedakan;
		int radiusLedakan;
		Buffer frameBuffer;
};

#endif
>>>>>>> 89d67ea23653560b473c76e0ad09c051d5706a08
