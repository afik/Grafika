#include <iostream>
#include "warna.h"
#include "pixel.h"
#include "bentuk.h"

using namespace std;

int main()
{
	Buffer buff;
	Warna warna;
	Pixel pixel;
	Bentuk bentuk;
	Point posisi(300,300);
	Point posisi2(300,400);
	int tempx=40, tempy=200, x,y=200,j;
	int t= 400, c = 1;

	for (x = 40; x<602; x++) {
		bentuk.circle(tempx,tempy,20,buff,*Warna::hitam());
		bentuk.circle(x,y,20,buff,*Warna::kuning());
		
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
