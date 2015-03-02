#include "pattern.h"

Pattern::Pattern()
{
	Warna biru(0,0,255);
	Warna hijau(0,255,0);
	Warna putih(255,255,255);
	
	for (int i = 0; i <10; i++) {
		for (int j=0;j<12;j++) {
			if ((i==0 && j==4) || (i==1 && j==3) || (i==1 && j==5) ||
				(i==2&&j==2) || (i==2&&j==6) || (i==2&&j==10) ||
				(i==3&&j==1) || (i==3&&j==4) || (i==3&&j==7) || (i==3&&j==9) ||
				(i==4&&j==0) || (i==4&&j==8) || (i==5&&j==1) || (i==5&&j==7) ||
				(i==6&&j==2) || (i==6&&j==6) || (i==6&&j==10) || 
				(i==7&&j==3) || (i==7&&j==5) || (i==8&&j==4)) {
					ikan[i][j] = putih;
				}
			else {
				ikan[i][j] = biru;
			}
		}
	}
	
	for (int i=0; i<5;i++) {
		for(int j=0; j<7; j++) {
			if ((i==1&&j==2) || (i==1&&j==4) ||
				(i==2&&j==1) || (i==2&&j==3) || (i==2&&j==5) ||
				(i==3&&j==0) || (i==3&&j==3) || (i==3&&j==6)) {
					burung[i][j] = putih;
				}
			else {
				burung[i][j] = hijau;
			}
		}
	}
}

Pattern::~Pattern()
{
	
}
