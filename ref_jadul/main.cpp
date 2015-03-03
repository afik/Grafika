#include<iostream>
#include "garis.h"
#include "pixel.h"

using namespace std;

int main()
{
	Point P1(200, 300);
	Point P2(500, 300);
	Point P3(600,300);
	Warna w(255,0,0);
	Warna w2(0,255,0);
	Buffer b;
	Pixel p;
	
	Garis g(P1, P2);
	g.drawLine(b,w);
	
	p.putPixel(w, P1, b);
	p.putPixel(w2,P3,b);
	
	cout << "warna : " << p.getPixel(P1, b).R << " " << p.getPixel(P1, b).G << " " << p.getPixel(P1,b).B << endl;
	
	b.closeBuffer();
	return 0;
}
