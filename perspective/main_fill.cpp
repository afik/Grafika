#include "fill_scan.h"
#include "balok1tm.h"

int main(){
	
	Warna putih;
	Buffer buff;
	Point P(700,500);
	Point Pt(900,300);
	/*Point p(400,400);
	Point p1(1000,700);
	Warna biru(0,255,255);
	f.fillPolygon(600, 450, putih, buff);
	f.fillRect(p, 100, 200, putih, buff);
	f.fillPattern(p1, 135, putih, biru, buff);*/
	Balok1TM B;
	B.drawBalok(Pt, P, 100, 100, 20, buff, putih);
	B.drawBalok(Pt, P.getX() + 100, P.getY(), 30, 40, 20, buff, putih);
	B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);
	//B.drawBalok(Pt, P.getX() + 130, P.getY(), 20, 50, 20, buff, putih);
	return 0;
}