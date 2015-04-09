#include "pointer.h"
#include <iostream>

void Pointer::drawPointer(Buffer buff){
	int p = 2;
	Warna warna;

	Point P1(0*p + posisi.getX(),0*p + posisi.getY());
	Point P2(5*p + posisi.getX(),2*p + posisi.getY());
    Point P3(3*p + posisi.getX(),3*p + posisi.getY());
    Point P4(3*p + posisi.getX(),5*p + posisi.getY());

    Garis P12(P1, P2);
    Garis P23(P2, P3);
    Garis P34(P3, P4);
    Garis P41(P4, P1);

    P12.drawLine(buff, warna);
    P23.drawLine(buff, warna);
    P34.drawLine(buff, warna);
    P41.drawLine(buff, warna);

}

void Pointer::clearPointer(Buffer buff){
	int p = 2;
	Warna warna(0,0,0);

	Point P1(0*p + posisi.getX(),0*p + posisi.getY());
	Point P2(5*p + posisi.getX(),2*p + posisi.getY());
    Point P3(3*p + posisi.getX(),3*p + posisi.getY());
    Point P4(3*p + posisi.getX(),5*p + posisi.getY());

    Garis P12(P1, P2);
    Garis P23(P2, P3);
    Garis P34(P3, P4);
    Garis P41(P4, P1);

    P12.drawLine(buff, warna);
    P23.drawLine(buff, warna);
    P34.drawLine(buff, warna);
    P41.drawLine(buff, warna);

}

void Pointer::setPosisi(Point P){
	this->posisi = P;
}

void Pointer::setPosisi(int x, int y){
	this->posisi.setX(x);
	this->posisi.setY(y);
}

void Pointer::putPixel(Warna warna, Buffer buff){
	Pixel p;

	p.putPixel(warna, posisi.getX()-1, posisi.getY()-1, buff);
}