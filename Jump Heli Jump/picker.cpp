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
	
	return w;
}

Warna Picker::getColour(int x, int y, Buffer buff)
{
	Pixel p;
	Warna w;
	
	w.setRed(p.getPixel(x, y, buff).getRed());
	w.setGreen(p.getPixel(x, y, buff).getGreen());
	w.setBlue(p.getPixel(x, y, buff).getBlue());
	
	return w;
}

void Picker::drawPicker(Buffer buff)
{
	int x, y;
	Pixel p;
	
	for ( y = 400; y < 450; y++ ) {
		//kotak 1
	    for ( x = 390; x < 440; x++ ) {
	        p.putPixel(*Warna::kuning(), x, y, buff);
	    }
	    
	    //kotak 2
	    for ( x = 470; x < 520; x++ ) {
	        p.putPixel(*Warna::putih(), x, y, buff);
	    }
	    
	    //kotak 3
	    for ( x = 550; x < 600; x++ ) {
	        p.putPixel(*Warna::merah(), x, y, buff);
	    }
	    
	    //kotak 4
	    for ( x = 630; x < 680; x++ ) {
	        p.putPixel(*Warna::biru(), x, y, buff);
	    }
	    
	    //kotak 5
	    for ( x = 710; x < 760; x++ ) {
	        p.putPixel(*Warna::hijau(), x, y, buff);
	    }
	    
	    //kotak 6
	    for ( x = 790; x < 840; x++ ) {
	        p.putPixel(*Warna::coklat(), x, y, buff);
	    }
	    
	    //kotak 7
	    for ( x = 870; x < 920; x++ ) {
	        p.putPixel(*Warna::ungu(), x, y, buff);
	    }
	    
	    //kotak 8
	    for ( x = 950; x < 1000; x++ ) {
	        p.putPixel(*Warna::oranye(), x, y, buff);
	    }
	}
	
	/** warna baris ke dua **/
	for ( y = 480; y < 530; y++ ) {
		//kotak 1
	    for ( x = 390; x < 440; x++ ) {
	        p.putPixel(*Warna::shockpink(), x, y, buff);
	    }
	    
	    //kotak 2
	    for ( x = 470; x < 520; x++ ) {
	        p.putPixel(*Warna::violet(), x, y, buff);
	    }
	    
	    //kotak 3
	    for ( x = 550; x < 600; x++ ) {
	        p.putPixel(*Warna::abu(), x, y, buff);
	    }
	    
	    //kotak 4
	    for ( x = 630; x < 680; x++ ) {
	        p.putPixel(*Warna::orenmuda(), x, y, buff);
	    }
	    
	    //kotak 5
	    for ( x = 710; x < 760; x++ ) {
	        p.putPixel(*Warna::softpink(), x, y, buff);
	    }
	    
	    //kotak 6
	    for ( x = 790; x < 840; x++ ) {
	        p.putPixel(*Warna::birulangit(), x, y, buff);
	    }
	    
	    //kotak 7
	    for ( x = 870; x < 920; x++ ) {
	        p.putPixel(*Warna::birutoska(), x, y, buff);
	    }
	    
	    //kotak 8
	    for ( x = 950; x < 1000; x++ ) {
	        p.putPixel(*Warna::pink(), x, y, buff);
	    }
	}
		
}
