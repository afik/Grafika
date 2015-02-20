#include "pixel.h"


void Pixel::putPixel(Warna warna,Point posisi, Buffer buf) {
	buf.setLocation(posisi.getX(), posisi.getY());
    *(buf.getFbp() + buf.getLocation()) = warna.B; // Some blue 
	*(buf.getFbp() + buf.getLocation() + 1) = warna.G; // A little green 
	*(buf.getFbp() + buf.getLocation() + 2) = warna.R; // A lot of red
	*(buf.getFbp() + buf.getLocation() + 3) = 0; // No transparency      
}

void Pixel::putPixel(Warna warna,int x, int y, Buffer buf) {
	buf.setLocation(x, y);
    *(buf.getFbp() + buf.getLocation()) = warna.B; // Some blue 
	*(buf.getFbp() + buf.getLocation() + 1) = warna.G; // A little green 
	*(buf.getFbp() + buf.getLocation() + 2) = warna.R; // A lot of red
	*(buf.getFbp() + buf.getLocation() + 3) = 0; // No transparency      
}

Warna Pixel::getPixel(Point posisi, Buffer buf){
	Warna warna;
	
	buf.setLocation(posisi.getX(), posisi.getY());
    warna.R = *(buf.getFbp() + buf.getLocation() + 2);
    if (warna.R<0) {
    	warna.R+=256;
    }
    warna.G = *(buf.getFbp() + buf.getLocation() + 1);
    if (warna.G<0) {
    	warna.G+=256;
    }
    warna.B = *(buf.getFbp() + buf.getLocation());
    if (warna.B<0) {
    	warna.B+=256;
    }
    
    return warna;
}

Warna Pixel::getPixel(int x, int y, Buffer buf){
	Warna warna;
	
	buf.setLocation(x, y);
    warna.R = *(buf.getFbp() + buf.getLocation() + 2);
    if (warna.R<0) {
    	warna.R+=256;
    }
    warna.G = *(buf.getFbp() + buf.getLocation() + 1);
    if (warna.G<0) {
    	warna.G+=256;
    }
    warna.B = *(buf.getFbp() + buf.getLocation());
    if (warna.B<0) {
    	warna.B+=256;
    }
    
    return warna;
}
