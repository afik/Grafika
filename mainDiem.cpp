#include <iostream>
#include "garis.h"
#include "fill.h"
#include "bentuk.h"
#include "pixel.h"

using namespace std;

int main()
{
	Buffer buf;
	Bentuk bentuk;
	Pixel p;
	
	Warna putih;
	Warna merah(255,0,0);
	Warna hijau(0,255,0);
	Warna biru(0,0,255);
	Warna hitam(0,0,0);
	
	Fill fill;
	
	//Titik-titik ikan di matriks
	/*Point offset(200,200);
	Point P1(0+offset.getX(),4+offset.getY());
	Point P2(4+offset.getX(),0+offset.getY());
	Point P3(4+offset.getX(),8+offset.getY());
	Point P4(10+offset.getX(),6+offset.getY());
	Point P5(10+offset.getX(),2+offset.getY());
	
	Garis g1(P1,P2); g1.drawLine(buf,putih);
	Garis g2(P1,P3); g2.drawLine(buf,putih);
	Garis g3(P2,P4); g3.drawLine(buf,putih);
	Garis g4(P3,P5); g4.drawLine(buf,putih);
	Warna bg = p.getPixel(offset.getX()+1,offset.getY()+4,buf);
	fill.FloodFill(offset.getX()+1,offset.getY()+4,bg,merah,buf);*/

	bentuk.kapal_laut(0,0,buf);
	bentuk.pesawat(0,0,buf);
	
	/*
	Garis g5(400,200,400,300);g5.drawLine(buf,putih);
	Garis g6(400,200,500,200);g6.drawLine(buf,putih);
	Garis g7(400,300,500,300);g7.drawLine(buf,putih);
	Garis g8(500,200,500,300);g8.drawLine(buf,putih);
	Warna bgkotak = p.getPixel(401,401,buf);
	//fill.patternFill(401,401,bgkotak,'i',buf);
	//fill.FloodFill(401,201,bgkotak,merah,buf);
	Point P(401,201);
	fill.patternFill(P,bgkotak,'b',buf);
	*/
	
	
	buf.closeBuffer();
	return 0;
}
