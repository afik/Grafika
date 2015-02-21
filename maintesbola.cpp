#include <iostream>
#include "warna.h"
#include "pixel.h"

using namespace std;

int main()
{
	void circle(int centerx, int centery, int Radius, Buffer buf, Warna w);
	Buffer buff;
	Warna warna;
	Pixel pixel;
	Point posisi(300,300);
	Point posisi2(300,400);
	int tempx=40, tempy=200, x,y=200,j;
	int t= 400, c = 1;

	for (x = 40; x<602; x++) {
		circle(tempx,tempy,20,buff,*Warna::hitam());
		circle(x,y,20,buff,*Warna::kuning());
		
		if(y >= 400) {
			c = 0;
			t -= 20;
		}
		if (y <=400-t) {
			c=1;
		}
		tempy = y;
		tempx = x;
		y = y + (c?15: -15);
		usleep(25000);
	}
	
	buff.closeBuffer();
	return 0;
}


void circle(int centerx, int centery, int Radius, Buffer buf, Warna w)
{

	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=centerx;
    int yCenter=centery;

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
