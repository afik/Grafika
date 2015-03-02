#include<iostream>
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
	Warna hitam(1,1,1);
	
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

	/*bentuk.kapal_laut(0,0,buf);
	Warna bgkapal = p.getPixel(55,330,buf);
	//fill.FloodFill(55,330,bgkapal,merah,buf);
	//fill.patternFill(55,330,bgkapal,'i',buf);
	Warna bgkapal2 = p.getPixel(101,299,buf);
	//fill.patternFill(101,299,bgkapal2,'b',buf);
	//fill.FloodFill(101,299,bgkapal2,merah,buf);
	*/
	
	/*
	bentuk.pesawat(0,0,buf);
	Warna bgpesawat = p.getPixel(540,67,buf);
	fill.patternFill(600,60,bgpesawat,'b',buf);
	fill.FloodFill(600,60,bgpesawat,merah,buf);
	*/
	
	/**
	Garis g5(400,200,400,300);g5.drawLine(buf,putih);
	Garis g6(400,200,500,200);g6.drawLine(buf,putih);
	Garis g7(400,300,500,300);g7.drawLine(buf,putih);
	Garis g8(500,200,500,300);g8.drawLine(buf,putih);
	Warna bgkotak = p.getPixel(401,401,buf);
	//fill.patternFill(401,401,bgkotak,'i',buf);
	fill.FloodFill(401,201,bgkotak,merah,buf);
	**/
	
	
	int v = 0;			// kecepatan
	int vp = 0;			// kecepatan
	int x =0;
	char clear;
	
	//peluru
	int x0 = 0, x1 = 0;
	int y0 = 0, y1 = 0;
	int y5 = 0;
	
	int iterate = 97;	// jumlah pengulangan
	while(iterate > 0){
		bentuk.hapus_pesawat(0,vp,buf);
		bentuk.pesawat(0,vp,buf);
		
		if(v < 50)
		{
			bentuk.hapus_kapal_laut(0,v-5,buf);
			bentuk.kapal_laut(0,v,buf);
			
		}
		else if(v>=50)
		{
			x = 50;
			bentuk.hapus_kapal_laut(0,x-5,buf);
			bentuk.kapal_laut(0,x,buf);
		}
		
		// Peluru miring 
		if((x==50) && (x0<200)){	
			Garis shadow(210-2+x0-5, 300-2-y0+5, 210+2+x1-5, 300+2-y1+5);
			shadow.drawLine(buf,hitam);
			Garis peluru(210-2+x0, 300-2-y0, 210+2+x1, 300+2-y1);
			peluru.drawLine(buf,putih);
			
			x0 = x0 + 5;
			x1 = x1 + 5;
			y0 = y0 + 5;
			y1 = y1 + 5;
		}
		// end of Peluru miring 
		if (x0==200){
			Garis shadow2(210-2+x0-5, 300-2-y0+5, 210+2+x1-5, 300+2-y1+5);
			shadow2.drawLine(buf,hitam);
		}
			
		// Pelru jatuh 
		if(vp <= -500){
			if(y5 <= 235){
				Garis shadow3(150, 71+y5-5, 154, 71+y5-5);
				shadow3.drawLine(buf,hitam);
				Garis peluru2(150, 71+y5, 154, 71+y5);
				peluru2.drawLine(buf,putih);
			
			}

			y5 = y5 + 5;
			
			if (y5 >235){
				Garis shadow4(150, 71+y5-5, 154, 71+y5-5);
				shadow4.drawLine(buf,hitam);
			}
		}
		Garis shadow5(150, 71+y5, 154, 71+y5);
		shadow5.drawLine(buf,hitam);

		// end of Peluru jatuh 
		if(y5 == 235){
			bentuk.boom(buf);
		}
		
		v = v + 5;			// kecepatan bertambah 5	
		vp = vp - 10;			// kecepatan bertambah 10
		
		iterate--;
		usleep(50000);
		
	}
	
	buf.closeBuffer();
	return 0;
}
