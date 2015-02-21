#include "bentuk.h"

Bentuk::Bentuk(){
	hitam.R=1;
	hitam.G=1;
	hitam.B=1;
}

void Bentuk::circle(Point center, int Radius, Buffer buf, Warna w)
{
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

void Bentuk::setengah_lingkaran(Point center, int Radius, Buffer buf) {
	Pixel p;
	Warna w;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=center.getX();
    int yCenter=center.getY();

    p0=(5/4)-Radius;

    p.putPixel(w,xCenter+x,yCenter-y,buf);
    p.putPixel(w,xCenter-x,yCenter-y,buf);
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
	    p.putPixel(w,xCenter+x,yCenter-y,buf);
	    p.putPixel(w,xCenter-x,yCenter-y,buf);
	    p.putPixel(w,xCenter+y,yCenter-x,buf);
	    p.putPixel(w,xCenter-y,yCenter-x,buf);
    }

    Garis diameter(center.getX()-Radius, center.getY(),center.getX()+Radius, center.getY());
    diameter.drawLine(buf,w);
}