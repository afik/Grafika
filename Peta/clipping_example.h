/**
 * 
 *	Referensi : http://electrofriends.com/source-codes/software-programs/c
 * 				/graphics/c-program-to-implement-the-cohen-sutherland-line-clipping-algorithm/ 
 * 
 */

#ifndef _CLIPPING_H
#define _CLIPPING_H

#include "garis.h"


enum { TOP = 0x1, BOTTOM = 0x2, RIGHT = 0x4, LEFT = 0x8 };

enum { FALSE, TRUE };

class clipping {
	public :
		clipping();														// default ctor
		clipping(float kiri, float kanan, float atas, float bawah); 	// ctor
		
		// PROSEDUR UTAMA
		// Menghitung kode titik (x,y) berdasarkan posisinya terhadap area clipping
		unsigned int compute_outcode (int x, int y);
		// Clipping garis dengan ujung-ujung (x1,y1) dan (x2,y2) terhadap area clipping berdasarkan kode titik ujung-ujung garis
		void doClippingCohenSutherland (double x1, double y1, double x2, double y2);
		// Pindahkan hasil clipping ke kotak view kecil di kanan bawah (asumsi ukuran 100 x 100)
		void shiftViewClip();
		
		// SETTER AND GETTER
		float getBatasAtasClipping();
		float getBatasBawahClipping();
		float getBatasKiriClipping();
		float getBatasKananClipping();
		void setBatasAtasClipping(float batasAtasClipping);
		void setBatasBawahClipping(float batasBawahClipping);
		void setBatasKananClipping(float batasKananClipping);
		void setBatasKiriClipping(float batasKiriClipping);
	
	private :		
		Buffer frameBuffer;
		float batasAtasClipping;
		float batasBawahClipping;
		float batasKiriClipping;
		float batasKananClipping;
};

#endif
