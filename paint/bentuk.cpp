#include "bentuk.h"

Bentuk::Bentuk(){
	
}
Bentuk::~Bentuk(){
	
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

void Bentuk::circle(int x0, int y0, int Radius, Buffer buf, Warna w)
{
	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=x0;
    int yCenter=y0;

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

void Bentuk::setengah_lingkaran(Point center, int Radius, Buffer buf, Warna w) {
	Pixel p;
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

void Bentuk::setengah_lingkaran(int x0, int y0, int Radius, Buffer buf, Warna w) {
	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=x0;
    int yCenter=y0;

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

    Garis diameter(x0-Radius, y0,x0+Radius, y0);
    diameter.drawLine(buf,w);
}

void Bentuk::persegi(Point kiriatas, int panjang, int lebar, Buffer buf, Warna w){
    Point P2(kiriatas.getX()+panjang, kiriatas.getY());
    Point P3(kiriatas.getX(), kiriatas.getY()+lebar);
    Point P4(kiriatas.getX()+panjang, kiriatas.getY()+lebar);

    Garis g1(kiriatas,P2); g1.drawLine(buf, w);
    Garis g2(P2,P4); g2.drawLine(buf, w);
    Garis g3(P4,P3); g3.drawLine(buf, w);
    Garis g4(P3,kiriatas); g4.drawLine(buf, w);
    
       
}