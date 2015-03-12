#include "awan.h"

Awan::Awan(Buffer buf, int x, int y, int rad){
	pos.setX(x);
	pos.setY(y);
	jari = rad;
	draw(buf);
}

Awan::~Awan(){

}

void Awan::draw(Buffer buf){
	Warna w(*Warna::biru());

	Point p1((pos.getX()-jari), (pos.getY()-(jari/4))); sudut[0] = p1;
	Point p2((pos.getX()-(jari/4)*3), (pos.getY()-(jari/4))); sudut[1] = p2;
	Point p3((pos.getX()-(jari/4)*3), (pos.getY()-(jari/4)*3)); sudut[2] = p3;
	Point p4((pos.getX()-(jari/2)), (pos.getY()-(jari/4)*3)); sudut[3] = p4;
	Point p5((pos.getX()-(jari/2)), (pos.getY()-jari)); sudut[4] = p5;
	Point p6((pos.getX()+(jari/4)*3), (pos.getY()-jari)); sudut[5] = p6;
	Point p7((pos.getX()+(jari/4)*3), (pos.getY()-(jari/4)*3)); sudut[6] = p7;
	Point p8((pos.getX()+(jari)), (pos.getY()-(jari/4)*3)); sudut[7] = p8;
	Point p9((pos.getX()+(jari)), (pos.getY()-(jari/8))); sudut[8] = p9;
	Point p10((pos.getX()+(jari/8)*10), (pos.getY()-(jari/8))); sudut[9] = p10;
	Point p11((pos.getX()+(jari/8)*10), (pos.getY()+(jari/4))); sudut[10] = p11;
	Point p16((pos.getX()-(jari)), (pos.getY()+(jari/4))); sudut[11] = p16;
	
	Garis g1(sudut[0],sudut[1]); g1.drawLine(buf, w);
	Garis g2(sudut[1],sudut[2]); g2.drawLine(buf, w);
	Garis g3(sudut[2],sudut[3]); g3.drawLine(buf, w);
	Garis g4(sudut[3],sudut[4]); g4.drawLine(buf, w);
	Garis g5(sudut[4],sudut[5]); g5.drawLine(buf, w);
	Garis g6(sudut[5],sudut[6]); g6.drawLine(buf, w);
	Garis g7(sudut[6],sudut[7]); g7.drawLine(buf, w);
	Garis g8(sudut[7],sudut[8]); g8.drawLine(buf, w);
	Garis g9(sudut[8],sudut[9]); g9.drawLine(buf, w);
	Garis g10(sudut[9],sudut[10]); g10.drawLine(buf, w);
	Garis g11(sudut[10],sudut[11]); g11.drawLine(buf, w);
	Garis g16(sudut[0],sudut[11]); g16.drawLine(buf, w);

}

int* Awan::getBoundary(){
	int *bound = new int[3];
	bound[0] = pos.getX() - jari; //x (kiri awan)
	bound[1] = pos.getY() - jari; //y atas
	bound[2] = pos.getY() + jari/4; //y bawah
	return bound;
}

Point Awan::getPosisi(){
	return pos;
}

int Awan::getRadius(){
	return jari;
}

void Awan::setPosisi(int x, int y){
	pos.setX(x);
	pos.setY(y);
}

void Awan::setRadius(int rad){
	jari = rad;
}