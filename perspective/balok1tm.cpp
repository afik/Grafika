#include "balok1tm.h"
#include <iostream>

void Balok1TM::drawBalok(Point Pt, Point P, int w, int h, int lebar, Buffer buff, Warna warna){
	// P titik kiri bawah
	// w : panjang sisi depan
	// h : lebar sisi depan
	// lebar : berapa jaraknya dengan sisi belakang

	fillScan f;

	Point P1(P.getX(),P.getY() - h);
	Point P2(P.getX() + w,P.getY() - h);
	Point P3(P.getX() + w, P.getY());
	Point P4(P.getX(),P.getY());
	
	Garis G12(P1,P2);
	Garis G23(P2,P3);
	Garis G34(P3,P4);
	Garis G14(P1,P4);
	
	G12.drawLine(buff, warna);
	G23.drawLine(buff, warna);
	G34.drawLine(buff, warna);
	G14.drawLine(buff, warna);

	/** Perspektif */
	Garis GP1(Pt,P1);
	Garis GP2(Pt,P2);
	Garis GP3(Pt,P3);
	Garis GP4(Pt,P4);
	/*
	GP1.drawLine(buff, warna);
	GP2.drawLine(buff, warna);
	GP3.drawLine(buff, warna);
	GP4.drawLine(buff, warna);
	*/
	
	/** Bangun */
	int j = P1.getY() - lebar;
	int i = f.GetX(GP1, j);
	Point P5(i, j);
	Garis Sisi1(P1, P5);
	Sisi1.drawLine(buff, warna);
	
	i = f.GetX(GP2, j);
	Point P6(i, j);
	Garis Sisi2(P2, P6);
	Sisi2.drawLine(buff, warna);

	j = f.GetY(GP4, P5.getX());
	i = P5.getX();
	Point P7(i, j);
	Garis Sisi3(P4, P7);
	Sisi3.drawLine(buff, warna);

	j = f.GetY(GP3, P6.getX());
	i = P6.getX();
	Point P8(i, j);
	Garis Sisi4(P3, P8);
	Sisi4.drawLine(buff, warna);

	/** Hubungkan garis */
	Garis G56(P5,P6);
	Garis G68(P6,P8);
	Garis G78(P7,P8);
	Garis G57(P5,P7);
	G56.drawLine(buff, warna);
	G68.drawLine(buff, warna);
	G78.drawLine(buff, warna);
	G57.drawLine(buff, warna);

}

void Balok1TM::drawBalok(Point Pt, int x, int y, int w, int h, int lebar, Buffer buff, Warna warna){
	// P titik kiri bawah
	// w : panjang sisi depan
	// h : lebar sisi depan
	// lebar : berapa jaraknya dengan sisi belakang
	
	fillScan f;

	Point P1(x, y - h);
	Point P2(x + w, y - h);
	Point P3(x + w, y);
	Point P4(x, y);
	
	Garis G12(P1,P2);
	Garis G23(P2,P3);
	Garis G34(P3,P4);
	Garis G14(P1,P4);
	
	G12.drawLine(buff, warna);
	G23.drawLine(buff, warna);
	G34.drawLine(buff, warna);
	G14.drawLine(buff, warna);

	/** Perspektif */
	Garis GP1(Pt,P1);
	Garis GP2(Pt,P2);
	Garis GP3(Pt,P3);
	Garis GP4(Pt,P4);
	/*
	GP1.drawLine(buff, warna);
	GP2.drawLine(buff, warna);
	GP3.drawLine(buff, warna);
	GP4.drawLine(buff, warna);
	*/
	
	/** Bangun */
	int j = P1.getY() - lebar;
	int i = f.GetX(GP1, j);
	Point P5(i, j);
	Garis Sisi1(P1, P5);
	Sisi1.drawLine(buff, warna);
	
	i = f.GetX(GP2, j);
	Point P6(i, j);
	Garis Sisi2(P2, P6);
	Sisi2.drawLine(buff, warna);

	j = f.GetY(GP4, P5.getX());
	i = P5.getX();
	Point P7(i, j);
	Garis Sisi3(P4, P7);
	Sisi3.drawLine(buff, warna);

	j = f.GetY(GP3, P6.getX());
	i = P6.getX();
	Point P8(i, j);
	Garis Sisi4(P3, P8);
	Sisi4.drawLine(buff, warna);

	/** Hubungkan garis */
	Garis G56(P5,P6);
	Garis G68(P6,P8);
	Garis G78(P7,P8);
	Garis G57(P5,P7);
	G56.drawLine(buff, warna);
	G68.drawLine(buff, warna);
	G78.drawLine(buff, warna);
	G57.drawLine(buff, warna);

}

void Balok1TM::drawBalokAtas(Point Pt, int x, int y, int w, int h, int lebar, Buffer buff, Warna warna){
	// P titik kiri bawah
	// w : panjang sisi depan
	// h : lebar sisi depan
	// lebar : berapa jaraknya dengan sisi belakang
	
	fillScan f;

	Point P1(x, y - h);
	Point P2(x + w, y - h);
	Point P3(x + w, y);
	Point P4(x, y);
	
	Garis G12(P1,P2);
	Garis G23(P2,P3);
	Garis G34(P3,P4);
	Garis G14(P1,P4);
	
	G12.drawLine(buff, warna);
	G23.drawLine(buff, warna);
	G34.drawLine(buff, warna);
	G14.drawLine(buff, warna);

	/** Perspektif */
	Garis GP1(Pt,P1);
	Garis GP2(Pt,P2);
	Garis GP3(Pt,P3);
	Garis GP4(Pt,P4);
	GP1.drawLine(buff, warna);
	GP2.drawLine(buff, warna);
	GP3.drawLine(buff, warna);
	GP4.drawLine(buff, warna);
	
	/** Bangun */
	int j = P1.getY() + lebar;
	int i = f.GetX(GP1, j);
	Point P5(i, j);
	Garis Sisi1(P1, P5);
	Sisi1.drawLine(buff, warna);
	
	i = f.GetX(GP2, j);
	Point P6(i, j);
	Garis Sisi2(P2, P6);
	Sisi2.drawLine(buff, warna);

	j = f.GetY(GP4, P5.getX());
	i = P5.getX();
	Point P7(i, j);
	Garis Sisi3(P4, P7);
	Sisi3.drawLine(buff, warna);

	j = f.GetY(GP3, P6.getX());
	i = P6.getX();
	Point P8(i, j);
	Garis Sisi4(P3, P8);
	Sisi4.drawLine(buff, warna);

	/** Hubungkan garis */
	Garis G56(P5,P6);
	Garis G68(P6,P8);
	Garis G78(P7,P8);
	Garis G57(P5,P7);
	G56.drawLine(buff, warna);
	G68.drawLine(buff, warna);
	G78.drawLine(buff, warna);
	G57.drawLine(buff, warna);

}

void Balok1TM::clear(Point Pt, int x, int y, int w, int h, int lebar, Buffer buff, Warna warna) {

	fillScan f;

	Point P1(x, y - h);
	Point P2(x + w, y - h);
	Point P3(x + w, y);
	Point P4(x, y);
	
	Garis G12(P1,P2);
	Garis G23(P2,P3);
	Garis G34(P3,P4);
	Garis G14(P1,P4);
	
	G12.drawLine(buff, warna);
	G23.drawLine(buff, warna);
	G34.drawLine(buff, warna);
	G14.drawLine(buff, warna);

	/** Perspektif */
	Garis GP1(Pt,P1);
	Garis GP2(Pt,P2);
	Garis GP3(Pt,P3);
	Garis GP4(Pt,P4);
	GP1.drawLine(buff, warna);
	GP2.drawLine(buff, warna);
	GP3.drawLine(buff, warna);
	GP4.drawLine(buff, warna);
	
	/** Bangun */
	int j = P1.getY() - lebar;
	int i = f.GetX(GP1, j);
	Point P5(i, j);
	Garis Sisi1(P1, P5);
	Sisi1.drawLine(buff, warna);
	
	i = f.GetX(GP2, j);
	Point P6(i, j);
	Garis Sisi2(P2, P6);
	Sisi2.drawLine(buff, warna);

	j = f.GetY(GP4, P5.getX());
	i = P5.getX();
	Point P7(i, j);
	Garis Sisi3(P4, P7);
	Sisi3.drawLine(buff, warna);

	j = f.GetY(GP3, P6.getX());
	i = P6.getX();
	Point P8(i, j);
	Garis Sisi4(P3, P8);
	Sisi4.drawLine(buff, warna);

	/** Hubungkan garis */
	Garis G56(P5,P6);
	Garis G68(P6,P8);
	Garis G78(P7,P8);
	Garis G57(P5,P7);
	G56.drawLine(buff, warna);
	G68.drawLine(buff, warna);
	G78.drawLine(buff, warna);
	G57.drawLine(buff, warna);
}
