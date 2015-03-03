#include "clipping_example.h"

clipping::clipping() {
	batasKiriClipping = 100;
	batasKananClipping = 400;
	batasAtasClipping = 400;
	batasBawahClipping = 100;	
}

clipping::clipping(float kiri, float kanan, float atas, float bawah) {
	batasKiriClipping = kiri;
	batasKananClipping = kanan;
	batasAtasClipping = atas;
	batasBawahClipping = bawah;
}

// PROSEDUR UTAMA

unsigned int clipping::compute_outcode(int x, int y)
{
    unsigned int oc = 0;
 
    if (y > batasAtasClipping) {
	    oc |= TOP;
	} else if (y < batasBawahClipping) {
	    oc |= BOTTOM;	
	}
	
    if (x > batasKananClipping) {
	    oc |= RIGHT;	
	} else if (x < batasKiriClipping) {
		oc |= LEFT;
	}
	
    return oc;
}
 
void clipping::doClippingCohenSutherland (double x1, double y1, double x2, double y2)
{
    int accept;
    int done;
    unsigned int outcode1, outcode2;
 
    accept = FALSE;
    done = FALSE;
 
    outcode1 = compute_outcode (x1, y1);
    outcode2 = compute_outcode (x2, y2);
    
    do {
		if (outcode1 == 0 && outcode2 == 0) {                // Kedua ujung garis berada di dalam area clipping
			accept = TRUE;
			done = TRUE;
		} else if (outcode1 & outcode2) {					 
			done = TRUE;
		} else {
			double x, y;
			int outcode_ex = outcode1 ? outcode1 : outcode2;
			
			if (outcode_ex & TOP) {
				x = x1 + (x2 - x1) * (batasAtasClipping - y1) / (y2 - y1);
				y = batasAtasClipping;
			} else if (outcode_ex & BOTTOM) {
				x = x1 + (x2 - x1) * (batasBawahClipping - y1) / (y2 - y1);
				y = batasBawahClipping;
			} else if (outcode_ex & RIGHT) {
				y = y1 + (y2 - y1) * (batasKananClipping - x1) / (x2 - x1);
				x = batasKananClipping;
			} else {
				y = y1 + (y2 - y1) * (batasKiriClipping - x1) / (x2 - x1);
				x = batasKiriClipping;
			}
			
			if (outcode_ex == outcode1) {
				x1 = x;
				y1 = y;
				outcode1 = compute_outcode (x1, y1);
			} else { 
				x2 = x;
				y2 = y;
				outcode2 = compute_outcode (x2, y2);
			}
		}
    } while (done == FALSE);
 
    if (accept == TRUE) {
		// Gambar garis hasil clipping dari titik (x1,y1) ke (x2,y2)
	    Garis garisClipping(x1,y1,x2,y2);
	    Warna warnaClipping(255,0,0); 				
	    garisClipping.drawLine(frameBuffer, warnaClipping);
	}
}

void clipping::shiftViewClip() {
	
}
 
// SETTER DAN GETTER

float clipping::getBatasAtasClipping() {
		return batasAtasClipping;
}
float clipping::getBatasBawahClipping() {
		return batasBawahClipping;
}
float clipping::getBatasKananClipping() {
		return batasKananClipping;
}
float clipping::getBatasKiriClipping() {
		return batasKiriClipping;
}
void clipping::setBatasAtasClipping(float batasAtasClipping) {
		this->batasAtasClipping = batasAtasClipping;
}
void clipping::setBatasBawahClipping(float batasBawahClipping) {
		this->batasBawahClipping = batasBawahClipping;
}
void clipping::setBatasKiriClipping(float batasKiriClipping) {
		this->batasKiriClipping = batasKiriClipping;
}
void clipping::setBatasKananClipping(float batasKananClipping) {
		this->batasKananClipping = batasKananClipping;
}
