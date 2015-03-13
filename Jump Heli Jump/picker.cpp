#include "picker.h"

Picker::Picker(){}
Picker::~Picker(){}

Warna Picker::getColour(Point P, Buffer buff)
{
	int x, y;
	Pixel p;
	Warna w;
	
	w.setRed(p.getPixel(P, buff).getRed());
	w.setGreen(p.getPixel(P, buff).getGreen());
	w.setBlue(p.getPixel(P, buff).getBlue());
	
	return warna;
}

void Picker::drawPicker(Buffer buff)
{
	int x, y;
	Pixel p;
	
	system("clear");
	
	for ( y = 300; y < 350; y++ ) {
		//kotak 1
	    for ( x = 50; x < 100; x++ ) {
	        p.putPixel(*Warna::kuning(), x, y, buff);
	    }
	    
	    //kotak 2
	    for ( x = 110; x < 160; x++ ) {
	        p.putPixel(*Warna::putih(), x, y, buff);
	    }
	    
	    //kotak 3
	    for ( x = 170; x < 220; x++ ) {
	        p.putPixel(*Warna::merah(), x, y, buff);
	    }
	    
	    //kotak 4
	    for ( x = 230; x < 280; x++ ) {
	        p.putPixel(*Warna::biru(), x, y, buff);
	    }
	    
	    //kotak 5
	    for ( x = 290; x < 340; x++ ) {
	        p.putPixel(*Warna::hijau(), x, y, buff);
	    }
	    
	    //kotak 6
	    for ( x = 350; x < 400; x++ ) {
	        p.putPixel(*Warna::coklat(), x, y, buff);
	    }
	    
	    //kotak 7
	    for ( x = 410; x < 460; x++ ) {
	        p.putPixel(*Warna::ungu(), x, y, buff);
	    }
	    
	    //kotak 8
	    for ( x = 470; x < 520; x++ ) {
	        p.putPixel(*Warna::oranye(), x, y, buff);
	    }
	}
	
}
