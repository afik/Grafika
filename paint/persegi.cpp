#include "persegi.h"
#include <iostream>

Persegi::Persegi(){
	Panjang = 0;
	Lebar = 0;
	KiriAtas.setX(0);
	KiriAtas.setY(0);
}

Persegi::~Persegi(){

}

void Persegi::drawPersegi(Warna warna, Buffer buff){
	Point P1(KiriAtas.getX(), KiriAtas.getY());
	Point P2(KiriAtas.getX() + Panjang, KiriAtas.getY());
	Point P3(KiriAtas.getX() + Panjang, KiriAtas.getY() + Lebar);
	Point P4(KiriAtas.getX(), KiriAtas.getY() + Lebar);

	Garis P12(P1, P2);
	Garis P23(P2, P3);
	Garis P34(P3, P4);
	Garis P14(P1, P4);

	P12.drawLine(buff, warna);
	P23.drawLine(buff, warna);
	P34.drawLine(buff, warna);
	P14.drawLine(buff, warna);
}
void Persegi::clearPersegi(Buffer buff){
	Warna warna(0,0,0);

	Point P1(KiriAtas.getX(), KiriAtas.getY());
	Point P2(KiriAtas.getX() + Panjang, KiriAtas.getY());
	Point P3(KiriAtas.getX() + Panjang, KiriAtas.getY() + Lebar);
	Point P4(KiriAtas.getX(), KiriAtas.getY() + Lebar);

	Garis P12(P1, P2);
	Garis P23(P2, P3);
	Garis P34(P3, P4);
	Garis P14(P1, P4);

	P12.drawLine(buff, warna);
	P23.drawLine(buff, warna);
	P34.drawLine(buff, warna);
	P14.drawLine(buff, warna);
}
void Persegi::setPanjang(int p){
	Panjang = p;
}
void Persegi::setLebar(int l){
	Lebar = l;
}
void Persegi::setKiriAtas(Point P){
	KiriAtas = P;
}