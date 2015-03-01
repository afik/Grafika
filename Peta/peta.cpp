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
Garis Peta::getGarisPulau(int pulauKe, int garisKe){
	switch(pulauKe){
		case 1 :{
			if(garisKe > 0 && garisKe < 6)
				return petaSumatra[garisKe-1];
			else return NULL;
			break;
		}
		case 2 :{
			if(garisKe > 0 && garisKe < 5)
				return petaJawa[garisKe-1];
			else return NULL;
			break;
		}
		case 3 :{
			if(garisKe > 0 && garisKe < 8)
				return petaKalimantan[garisKe-1];
			else return NULL;
			break;
		}
		case 4 :{
			if(garisKe > 0 && garisKe <= 13)
				return petaSulawesi[garisKe-1];
			else return NULL;
			break;
		}
		default :{
			return NULL;
			break;
		}
	}
}
void Peta::pulauSumatra(int y, Buffer buff){
	Point p1(2,22+y);Point p2(2,7+y);Point p3(68,21+y);Point p4(316,205+y);Point p5(303,256+y);Point p6(266, 337 + y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p6); Garis g6(p6,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);g6.drawLine(buff,putih);
	petaSumatra[0] = g1;petaSumatra[1] = g2;petaSumatra[2] = g3;petaSumatra[3] = g4;petaSumatra[4] = g5;petaSumatra[5] = g6;
}
void Peta::pulauJawa(int y, Buffer buff){
	Point p1(293,362 + y);Point p2(312,336 + y);Point p3(564,398+y);Point p4(562,419+y);Point p5(288,366+y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);
	petaJawa[0] = g1;petaJawa[1] = g2;petaJawa[2] = g3;petaJawa[3] = g4;petaJawa[4] = g5;
}
void Peta::pulauKalimantan(int y, Buffer buff){
	Point p1(407,108 + y);Point p2(438,137 + y);Point p3(551,120+y);Point p4(587,42+y);Point p5(641,48+y);Point p6(670, 142 + y);Point p7(595,280+y);Point p8(426, 250 + y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p6); Garis g6(p6,p7); Garis g7(p7,p8); Garis g8(p8,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);g6.drawLine(buff,putih);g7.drawLine(buff,putih);g8.drawLine(buff,putih);
	petaKalimantan[0] = g1;petaKalimantan[1] = g2;petaKalimantan[2] = g3;petaKalimantan[3] = g4;petaKalimantan[4] = g5;petaKalimantan[5] = g6;petaKalimantan[6] = g7;petaKalimantan[7] = g8;
}
void Peta::pulauSulawesi(int y, Buffer buff){
	Point p1(859,118 + y);Point p2(852,140 + y);Point p3(719,162+y);Point p4(728,206+y);Point p5(798,185+y);Point p6(810, 203 + y);Point p7(750,225+y);Point p8(807,310 + y);Point p9(773,328+ y);Point p10(732,257 + y);Point p11(715,331 + y);Point p12(688,327 + y);Point p13(694,162 + y);
	Garis g1(p1,p2); Garis g2(p2,p3); Garis g3(p3,p4); Garis g4(p4,p5); Garis g5(p5,p6); Garis g6(p6,p7); Garis g7(p7,p8); Garis g8(p8,p9); Garis g9(p9,p10); Garis g10(p10,p11); Garis g11(p11,p12); Garis g12(p12,p13); Garis g13(p13,p1);
	g1.drawLine(buff,putih);g2.drawLine(buff,putih);g3.drawLine(buff,putih);g4.drawLine(buff,putih);g5.drawLine(buff,putih);g6.drawLine(buff,putih);g7.drawLine(buff,putih);g8.drawLine(buff,putih);g9.drawLine(buff,putih);g10.drawLine(buff,putih);g11.drawLine(buff,putih);g12.drawLine(buff,putih);g13.drawLine(buff,putih);
	petaSulawesi[0] = g1;petaSulawesi[1] = g2;petaSulawesi[2] = g3;petaSulawesi[3] = g4;petaSulawesi[4] = g5;petaSulawesi[5] = g6;petaSulawesi[6] = g7;petaSulawesi[7] = g8;petaSulawesi[8] = g9;petaSulawesi[9] = g10;petaSulawesi[10] = g11;petaSulawesi[11] = g12;petaSulawesi[12] = g13;
}