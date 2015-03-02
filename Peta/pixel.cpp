#include "pixel.h"

void Pixel::putPixel(Warna warna,Point posisi, Buffer buf) {
	buf.setLocation(posisi.getX(), posisi.getY());
    *(buf.getFbp() + buf.getLocation()) = warna.getBlue(); // Some blue 
	*(buf.getFbp() + buf.getLocation() + 1) = warna.getGreen(); // A little green 
	*(buf.getFbp() + buf.getLocation() + 2) = warna.getRed(); // A lot of red
	*(buf.getFbp() + buf.getLocation() + 3) = 0; // No transparency      
}

void Pixel::putPixel(Warna warna,int x, int y, Buffer buf) {
	buf.setLocation(x, y);
    *(buf.getFbp() + buf.getLocation()) = warna.getBlue(); // Some blue 
	*(buf.getFbp() + buf.getLocation() + 1) = warna.getGreen(); // A little green 
	*(buf.getFbp() + buf.getLocation() + 2) = warna.getRed(); // A lot of red
	*(buf.getFbp() + buf.getLocation() + 3) = 0; // No transparency      
}

Warna Pixel::getPixel(Point posisi, Buffer buf){
	Warna warna;
	
	buf.setLocation(posisi.getX(), posisi.getY());
    warna.setRed(*(buf.getFbp() + buf.getLocation() + 2));
    if (warna.getRed()<0) {
    	warna.setRed(warna.getRed() + 256);
    }
    warna.setGreen(*(buf.getFbp() + buf.getLocation() + 1));
    if (warna.getGreen()<0) {
    	warna.setGreen(warna.getGreen() + 256);
    }
    warna.setBlue(*(buf.getFbp() + buf.getLocation()));
    if (warna.getBlue()<0) {
    	warna.setBlue(warna.getBlue() + 256);
    }
    
    return warna;
}

Warna Pixel::getPixel(int x, int y, Buffer buf){
	Warna warna;
	
	buf.setLocation(x, y);
    warna.setRed(*(buf.getFbp() + buf.getLocation() + 2));
    if (warna.getRed()<0) {
    	warna.setRed(warna.getRed() + 256);
    }
    warna.setGreen(*(buf.getFbp() + buf.getLocation() + 1));
    if (warna.getGreen()<0) {
    	warna.setGreen(warna.getGreen() + 256);
    }
    warna.setBlue(*(buf.getFbp() + buf.getLocation()));
    if (warna.getBlue()<0) {
    	warna.setBlue(warna.getBlue() + 256);
    }
    
    return warna;
}
