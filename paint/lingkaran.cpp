#include "lingkaran.h"
#include <iostream>

Lingkaran::Lingkaran(){
	Radius = 0;
	center.setX(0);
	center.setY(0);
}

Lingkaran::~Lingkaran(){

}

void Lingkaran::drawLingkaran(Warna w, Buffer buf){
	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=center.getX();
    int yCenter=center.getY();

    p0=(5/4)-Radius;

    p.putPixel(w,xCenter+x,yCenter+y,buf);
    p.putPixel(w,xCenter-x,yCenter+y,buf);
    p.putPixel(w,xCenter+x,yCenter-y,buf);
    p.putPixel(w,xCenter-x,yCenter-y,buf);
    p.putPixel(w,xCenter+y,yCenter+x,buf);
    p.putPixel(w,xCenter-y,yCenter+x,buf);
    p.putPixel(w,xCenter+y,yCenter-x,buf);
    p.putPixel(w,xCenter-y,yCenter-x,buf);


    while(x<=y)
    {
        if(p0 < 0)
        {
            p0=p0 + 2*(x+1) + 1;
            x=x+1;
        }
        else
        {
            p0=p0 + 2*(x+1) + 1 - 2*(y-1);
            x=x+1;
            y=y-1;
        }
	    p.putPixel(w,xCenter+x,yCenter+y,buf);
	    p.putPixel(w,xCenter-x,yCenter+y,buf);
	    p.putPixel(w,xCenter+x,yCenter-y,buf);
	    p.putPixel(w,xCenter-x,yCenter-y,buf);
	    p.putPixel(w,xCenter+y,yCenter+x,buf);
	    p.putPixel(w,xCenter-y,yCenter+x,buf);
	    p.putPixel(w,xCenter+y,yCenter-x,buf);
	    p.putPixel(w,xCenter-y,yCenter-x,buf);
    }



}
void Lingkaran::clearLingkaran(Buffer buf){
	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=center.getX();
    int yCenter=center.getY();
    Warna w(0,0,0);

    p0=(5/4)-Radius;

    p.putPixel(w,xCenter+x,yCenter+y,buf);
    p.putPixel(w,xCenter-x,yCenter+y,buf);
    p.putPixel(w,xCenter+x,yCenter-y,buf);
    p.putPixel(w,xCenter-x,yCenter-y,buf);
    p.putPixel(w,xCenter+y,yCenter+x,buf);
    p.putPixel(w,xCenter-y,yCenter+x,buf);
    p.putPixel(w,xCenter+y,yCenter-x,buf);
    p.putPixel(w,xCenter-y,yCenter-x,buf);


    while(x<=y)
    {
        if(p0 < 0)
        {
            p0=p0 + 2*(x+1) + 1;
            x=x+1;
        }
        else
        {
            p0=p0 + 2*(x+1) + 1 - 2*(y-1);
            x=x+1;
            y=y-1;
        }
	    p.putPixel(w,xCenter+x,yCenter+y,buf);
	    p.putPixel(w,xCenter-x,yCenter+y,buf);
	    p.putPixel(w,xCenter+x,yCenter-y,buf);
	    p.putPixel(w,xCenter-x,yCenter-y,buf);
	    p.putPixel(w,xCenter+y,yCenter+x,buf);
	    p.putPixel(w,xCenter-y,yCenter+x,buf);
	    p.putPixel(w,xCenter+y,yCenter-x,buf);
	    p.putPixel(w,xCenter-y,yCenter-x,buf);
    }
}
void Lingkaran::setRadius(int r){
	Radius = r;

}
void Lingkaran::setCenter(Point p){
	center = p;
}