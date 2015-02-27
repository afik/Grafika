#include "peta.h"

Peta::Peta(){

}
Peta::~Peta(){

}
void Peta::gambarPeta(int y, Buffer buff){
	  pulauSumatra(y,buff);
	  pulauJawa(y,buff);
	  pulauKalimantan(y,buff);
	  pulauSulawesi(y,buff);
}
void Peta::pulauSumatra(int y, Buffer buff){
	Point p1(2,22 + y);Point p2(2,7 + y);Point p3(68,21+y);Point p4(316,256+y);Point p5(303,205+y);Point p6(266, 337 + y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p6); Garis g6(p6,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);g6.drawLine(buff,putih);
}
void Peta::pulauJawa(int y, Buffer buff){
	Point p1(293,362 + y);Point p2(312,336 + y);Point p3(564,398+y);Point p4(562,419+y);Point p5(288,366+y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);
}
void Peta::pulauKalimantan(int y, Buffer buff){
	Point p1(407,108 + y);Point p2(438,137 + y);Point p3(551,120+y);Point p4(587,42+y);Point p5(641,48+y);Point p6(670, 142 + y);Point p7(595,280+y);Point p8(426, 250 + y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p6); Garis g6(p6,p7); Garis g7(p7,p8); Garis g8(p8,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);g6.drawLine(buff,putih);g7.drawLine(buff,putih);g8.drawLine(buff,putih);
}
void Peta::pulauSulawesi(int y, Buffer buff){
	Point p1(859,118 + y);Point p2(852,140 + y);Point p3(719,162+y);Point p4(728,206+y);Point p5(798,185+y);Point p6(810, 203 + y);Point p7(750,225+y);Point p8(807,310 + y);Point p9(773,328+ y);Point p10(732,257 + y);Point p11(715,331 + y);Point p12(688,327 + y);Point p13(694,162 + y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p6); Garis g6(p6,p7); Garis g7(p7,p8); Garis g8(p8,p9); Garis g9(p9,p10); Garis g10(p10,p11); Garis g11(p11,p12); Garis g12(p12,p13); Garis g13(p13,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);g6.drawLine(buff,putih);g7.drawLine(buff,putih);g8.drawLine(buff,putih);g9.drawLine(buff,putih);g10.drawLine(buff,putih);g11.drawLine(buff,putih);g12.drawLine(buff,putih);g13.drawLine(buff,putih);
}