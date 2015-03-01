#include "scanline.h"

Scanline::Scanline(){
	G1.getPointP1().setX(0);
	G1.getPointP1().setY(0);
	G1.getPointP2().setX(0);
	G1.getPointP2().setY(0);
}

Scanline::Scanline(Garis G1, Garis G2){
	this->G1 = G1;
	this->G2 = G2;
}

Scanline::~Scanline(){}

bool Scanline::isBerpotongan (int x, int y, Garis G){
	return ((y-G.getPointP1().getY())*(G.getPointP2().getX()-G.getPointP1().getX()) == (x-G.getPointP1().getX())*(G.getPointP2().getY()-G.getPointP1().getY()));	
}

void Scanline::drawScanline (int x0, int y0, int x1, int y1, Garis G1, Garis G2, Warna warna){
	int i = 0;
	int j = 0;
	Point GPotong[2];
	Buffer b;
	// testing warna
	for(j=y0; j<=y1; j++){
		for(i=x0; i<=x1; i++){
			if(isBerpotongan(i,j,G1)){
				GPotong[0].setX(i); GPotong[0].setY(j);
			}else{
				GPotong[0].setX(((j - G1.getPointP1().getY())*(G1.getPointP2().getX() - G1.getPointP1().getX()) / (G1.getPointP2().getY() - G1.getPointP1().getY())) + G1.getPointP1().getX());
				GPotong[0].setY(j);
			}
			if(isBerpotongan(i,j,G2)){
				GPotong[0].setX(i); GPotong[0].setY(j);
			}else{
				GPotong[1].setX(((j - G2.getPointP1().getY())*(G2.getPointP2().getX() - G2.getPointP1().getX()) / (G2.getPointP2().getY() - G2.getPointP1().getY())) + G2.getPointP1().getX()); 
				GPotong[1].setY(j);
			}
		}	
		Garis G(GPotong[0].getX(), GPotong[0].getY(), GPotong[1].getX(), GPotong[1].getY());
		G.drawLine(b, warna);
	}	
}

//void Scanline::setGaris1(){}
//void Scanline::seGaris2(){}
