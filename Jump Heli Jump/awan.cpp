#include "awan.h"

Awan::Awan(){
	jari = 50;
}

Awan::Awan(int x, int y, int rad){
	pos.setX(x);
	pos.setY(y);
	jari = rad;
}

Awan::~Awan(){

}

void Awan::draw(Buffer buf){
	// printf("enter draw\n");
	// printf("%d %d %d\n", pos.getX(), pos.getY(), jari);
	Warna w = *Warna::biru();

	Point p1((pos.getX()-jari), (pos.getY()-(jari/4))); 
	Point p2((pos.getX()-(jari/4)*3), (pos.getY()-(jari/4))); 
	Point p3((pos.getX()-(jari/4)*3), (pos.getY()-(jari/4)*3)); 
	Point p4((pos.getX()-(jari/2)), (pos.getY()-(jari/4)*3));
	Point p5((pos.getX()-(jari/2)), (pos.getY()-jari)); 
	Point p6((pos.getX()+(jari/4)*3), (pos.getY()-jari)); 
	Point p7((pos.getX()+(jari/4)*3), (pos.getY()-(jari/4)*3));
	Point p8((pos.getX()+(jari)), (pos.getY()-(jari/4)*3)); 
	Point p9((pos.getX()+(jari)), (pos.getY()-(jari/8))); 
	Point p10((pos.getX()+(jari/8)*10), (pos.getY()-(jari/8))); 
	Point p11((pos.getX()+(jari/8)*10), (pos.getY()+(jari/4))); 
	Point p16((pos.getX()-(jari)), (pos.getY()+(jari/4))); 

	Garis g1(p1,p2); g1.drawLine(buf, w);
	Garis g2(p2,p3); g2.drawLine(buf, w);
	Garis g3(p3,p4); g3.drawLine(buf, w);
	Garis g4(p4,p5); g4.drawLine(buf, w);
	Garis g5(p5,p6); g5.drawLine(buf, w);
	Garis g6(p6,p7); g6.drawLine(buf, w);
	Garis g7(p7,p8); g7.drawLine(buf, w);
	Garis g8(p8,p9); g8.drawLine(buf, w);
	Garis g9(p9,p10); g9.drawLine(buf, w);
	Garis g10(p10,p11); g10.drawLine(buf, w);
	Garis g11(p11,p16); g11.drawLine(buf, w);
	Garis g16(p16,p1); g16.drawLine(buf, w);

	allLine[0] = g1;
	allLine[1] = g2;
	allLine[2] = g3;
	allLine[3] = g4;
	allLine[4] = g5;
	allLine[5] = g6;
	allLine[6] = g7;
	allLine[7] = g8;
	allLine[8] = g9;
	allLine[9] = g10;
	allLine[10] = g11;
	allLine[11] = g16;
	
	// printf("out draw\n");
	

}

void Awan::clear(Buffer buf){
	// printf("enter clear\n");
	// printf("%d %d %d\n", pos.getX(), pos.getY(), jari);
	Warna w = *Warna::hitam();

	Point p1((pos.getX()-jari), (pos.getY()-(jari/4))); 
	Point p2((pos.getX()-(jari/4)*3), (pos.getY()-(jari/4))); 
	Point p3((pos.getX()-(jari/4)*3), (pos.getY()-(jari/4)*3)); 
	Point p4((pos.getX()-(jari/2)), (pos.getY()-(jari/4)*3));
	Point p5((pos.getX()-(jari/2)), (pos.getY()-jari)); 
	Point p6((pos.getX()+(jari/4)*3), (pos.getY()-jari)); 
	Point p7((pos.getX()+(jari/4)*3), (pos.getY()-(jari/4)*3));
	Point p8((pos.getX()+(jari)), (pos.getY()-(jari/4)*3)); 
	Point p9((pos.getX()+(jari)), (pos.getY()-(jari/8))); 
	Point p10((pos.getX()+(jari/8)*10), (pos.getY()-(jari/8))); 
	Point p11((pos.getX()+(jari/8)*10), (pos.getY()+(jari/4))); 
	Point p16((pos.getX()-(jari)), (pos.getY()+(jari/4))); 

	Garis g1(p1,p2); g1.drawLine(buf, w);
	Garis g2(p2,p3); g2.drawLine(buf, w);
	Garis g3(p3,p4); g3.drawLine(buf, w);
	Garis g4(p4,p5); g4.drawLine(buf, w);
	Garis g5(p5,p6); g5.drawLine(buf, w);
	Garis g6(p6,p7); g6.drawLine(buf, w);
	Garis g7(p7,p8); g7.drawLine(buf, w);
	Garis g8(p8,p9); g8.drawLine(buf, w);
	Garis g9(p9,p10); g9.drawLine(buf, w);
	Garis g10(p10,p11); g10.drawLine(buf, w);
	Garis g11(p11,p16); g11.drawLine(buf, w);
	Garis g16(p16,p1); g16.drawLine(buf, w);
	// printf("out clear\n");
	
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