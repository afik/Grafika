#include "fill_scan.h"
#include <iostream>
int fillScan::GetX(Garis G, int y){ return ((y - G.getPointP1().getY())*(G.getPointP2().getX() - G.getPointP1().getX())/(G.getPointP2().getY() - G.getPointP1().getY())) + G.getPointP1().getX(); }

fillScan::fillScan() {
	//numLine =0;
}

void fillScan::fill(int y0, int y1, Garis G1, Garis G2, Warna warna, Buffer buff){	
	for(int j = y0; j < y1 ; j++){ 
		Point Pi(GetX(G1,j) , j); 
		Point Pj(GetX(G2,j) , j); 
		Garis g(Pi, Pj); g.drawLine(buff,warna); 
	}	
}
void fillScan::fillPolygon(int x, int y, Warna warna, Buffer buff){
		/** kotak besar */
		Point P1(x-75,y);
		Point P2(x,y);
		Point P4(x-75,y+90);
		Point P3(x,y+90);
		Garis G12(P1, P2);
		Garis G23(P2, P3);
		Garis G34(P3, P4);
		Garis G14(P1, P4);

		G12.drawLine(buff, warna);
		G23.drawLine(buff, warna);
		G34.drawLine(buff, warna);
		G14.drawLine(buff, warna);

		/** jendela 4 */
		Point P4a(P3.getX() - 45, P3.getY() - 45);
		Point P4b(P3.getX() - 60, P3.getY() - 45);
		Point P4c(P3.getX() - 60, P3.getY() - 30);
		Point P4d(P3.getX() - 45, P3.getY() - 30);

		Garis G4ab(P4a, P4b);
		Garis G4bc(P4b, P4c);
		Garis G4cd(P4c, P4d);
		Garis G4ad(P4a, P4d);

		G4ab.drawLine(buff, warna);
		G4bc.drawLine(buff, warna);
		G4cd.drawLine(buff, warna);
		G4ad.drawLine(buff, warna);

		/** jendela 3 */
		Point P3a(P3.getX() - 45 + 30 , P3.getY() - 45);
		Point P3b(P3.getX() - 60 + 30 , P3.getY() - 45);
		Point P3c(P3.getX() - 60 + 30, P3.getY() - 30);
		Point P3d(P3.getX() - 45 + 30, P3.getY() - 30);

		Garis G3ab(P3a, P3b);
		Garis G3bc(P3b, P3c);
		Garis G3cd(P3c, P3d);
		Garis G3ad(P3a, P3d);

		G3ab.drawLine(buff, warna);
		G3bc.drawLine(buff, warna);
		G3cd.drawLine(buff, warna);
		G3ad.drawLine(buff, warna);

		/** jendela 2 */
		Point P2a(P3.getX() - 45 + 30 , P3.getY() - 45 - 30);
		Point P2b(P3.getX() - 60 + 30 , P3.getY() - 45 - 30);
		Point P2c(P3.getX() - 60 + 30, P3.getY() - 30 - 30);
		Point P2d(P3.getX() - 45 + 30, P3.getY() - 30 - 30);

		Garis G2ab(P2a, P2b);
		Garis G2bc(P2b, P2c);
		Garis G2cd(P2c, P2d);
		Garis G2ad(P2a, P2d);

		G2ab.drawLine(buff, warna);
		G2bc.drawLine(buff, warna);
		G2cd.drawLine(buff, warna);
		G2ad.drawLine(buff, warna);

		/** jendela 1 */
		Point P1a(P3.getX() - 45 , P3.getY() - 45 - 30);
		Point P1b(P3.getX() - 60 , P3.getY() - 45 - 30);
		Point P1c(P3.getX() - 60 , P3.getY() - 30 - 30);
		Point P1d(P3.getX() - 45 , P3.getY() - 30 - 30);

		Garis G1ab(P1a, P1b);
		Garis G1bc(P1b, P1c);
		Garis G1cd(P1c, P1d);
		Garis G1ad(P1a, P1d);

		G1ab.drawLine(buff, warna);
		G1bc.drawLine(buff, warna);
		G1cd.drawLine(buff, warna);
		G1ad.drawLine(buff, warna);

		/** warnai */
		
		fill(P1.getY(), P1a.getY(), G14, G23, warna, buff);
		fill(P4d.getY(), P4.getY(), G14, G23, warna, buff);
		fill(P1d.getY(), P4a.getY(), G14, G23, warna, buff);
		fill(P1a.getY(), P1d.getY(), G14, G1bc, warna, buff);
		fill(P1a.getY(), P1d.getY(), G1ad, G2bc, warna, buff);
		fill(P1a.getY(), P1d.getY(), G2ad, G23, warna, buff);
		fill(P4a.getY(), P4d.getY(), G14, G1bc, warna, buff);
		fill(P4a.getY(), P4d.getY(), G1ad, G2bc, warna, buff);
		fill(P4a.getY(), P4d.getY(), G2ad, G23, warna, buff);
	}

void fillScan::fillRect(Point P, int w, int h, Warna warna, Buffer buff){	
	Point Paa(P.getX(),P.getY());	Point Pab(P.getX(), P.getY()-h);
	Point Pbb(P.getX()+w,P.getY()); Point Pba(P.getX()+w,P.getY()-h);
	Garis G1(Paa,Pab);
	Garis G2(Pbb,Pba);
	//cout << G1.getPointP1().getX() <<endl;
	for(int j = Pab.getY(); j < Paa.getY(); j++){ 
		Point Pi(GetX(G1,j) , j); 
		Point Pj(GetX(G2,j) , j); 
		Garis g(Pi, Pj); 
		g.drawLine(buff,warna); 
		//allLine[numLine] = g;
		//numLine++;
	}	
}
void fillScan::fillRect(int x, int y, int w, int h, Warna warna, Buffer buff){	
	Point Paa(x,y);	Point Pab(x, y-h);
	Point Pbb(x+w,y); Point Pba(x+w,y-h);
	Garis G1(Paa,Pab);
	Garis G2(Pbb,Pba);
	//cout << G1.getPointP1().getX() <<endl;
	for(int j = Pab.getY(); j < Paa.getY(); j++){ 
		Point Pi(GetX(G1,j) , j); 
		Point Pj(GetX(G2,j) , j); 
		Garis g(Pi, Pj); 
		g.drawLine(buff,warna); 
		//allLine[numLine] = g;
		//numLine++;
	}	
}
void fillScan::fillPattern(Point P, int h, Warna warna1, Warna warna2, Buffer buff){
	fillRect(P, 75, 30, warna1, buff);
	int j = 0;
	h = h - 15;
	bool baris =  false;
	while(j < h - 15){
		if(baris==false){
			fillRect(P.getX()     , P.getY() - 30 - j, 15, 15, warna1, buff);
			fillRect(P.getX() + 15, P.getY() - 30 - j, 15, 15, warna2, buff);
			fillRect(P.getX() + 30, P.getY() - 30 - j, 15, 15, warna1, buff);
			fillRect(P.getX() + 45, P.getY() - 30 - j, 15, 15, warna2, buff);
			fillRect(P.getX() + 60, P.getY() - 30 - j, 15, 15, warna1, buff);
			baris = true;			
		}else{
			/** pattern anyaman */
/*			fillRect(P.getX()     , P.getY() - 30 - j, 15, 15, warna2, buff);
			fillRect(P.getX() + 15, P.getY() - 30 - j, 15, 15, warna1, buff);
			fillRect(P.getX() + 30, P.getY() - 30 - j, 15, 15, warna2, buff);
			fillRect(P.getX() + 45, P.getY() - 30 - j, 15, 15, warna1, buff);
			fillRect(P.getX() + 60, P.getY() - 30 - j, 15, 15, warna2, buff);
*/			
			/** pattern jendela */
			fillRect(P.getX()     , P.getY() - 30 - j, 75, 15, warna1, buff);
			baris = false;
		}
		j = j + 15;
	}
		fillRect(P.getX(), P.getY() - h, 75, 15, warna1, buff);
	
}
