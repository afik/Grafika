#include "bentuk.h"


Bentuk::Bentuk(){
	hitam.R=1;
	hitam.G=1;
	hitam.B=1;
}

void Bentuk::circle(Point center, int Radius, Buffer buf, Warna w)
{
	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=center.getX();
    int yCenter=center.getY();

    p0=(5/4)-Radius;

    p.putPixel(w,xCenter+x,yCenter+y,buf);
    p.putPixel(w,xCenter-x,yCenter+y,buf);
    p.putPixel(w,xCenter+x,yCenter-y,buf);
    p.putPixel(w,xCenter-x,yCenter-y,buf);
    p.putPixel(w,xCenter+y,yCenter+x,buf);
    p.putPixel(w,xCenter-y,yCenter+x,buf);
    p.putPixel(w,xCenter+y,yCenter-x,buf);
    p.putPixel(w,xCenter-y,yCenter-x,buf);


    while(x<=y)
    {
        if(p0 < 0)
        {
            p0=p0 + 2*(x+1) + 1;
            x=x+1;
        }
        else
        {
            p0=p0 + 2*(x+1) + 1 - 2*(y-1);
            x=x+1;
            y=y-1;
        }
	    p.putPixel(w,xCenter+x,yCenter+y,buf);
	    p.putPixel(w,xCenter-x,yCenter+y,buf);
	    p.putPixel(w,xCenter+x,yCenter-y,buf);
	    p.putPixel(w,xCenter-x,yCenter-y,buf);
	    p.putPixel(w,xCenter+y,yCenter+x,buf);
	    p.putPixel(w,xCenter-y,yCenter+x,buf);
	    p.putPixel(w,xCenter+y,yCenter-x,buf);
	    p.putPixel(w,xCenter-y,yCenter-x,buf);
    }
}

void Bentuk::setengah_lingkaran(Point center, int Radius, Buffer buf) {
	Pixel p;
	Warna w;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=center.getX();
    int yCenter=center.getY();

    p0=(5/4)-Radius;

    p.putPixel(w,xCenter+x,yCenter-y,buf);
    p.putPixel(w,xCenter-x,yCenter-y,buf);
    p.putPixel(w,xCenter+y,yCenter-x,buf);
    p.putPixel(w,xCenter-y,yCenter-x,buf);


    while(x<=y)
    {
        if(p0 < 0)
        {
            p0=p0 + 2*(x+1) + 1;
            x=x+1;
        }
        else
        {
            p0=p0 + 2*(x+1) + 1 - 2*(y-1);
            x=x+1;
            y=y-1;
        }
	    p.putPixel(w,xCenter+x,yCenter-y,buf);
	    p.putPixel(w,xCenter-x,yCenter-y,buf);
	    p.putPixel(w,xCenter+y,yCenter-x,buf);
	    p.putPixel(w,xCenter-y,yCenter-x,buf);
    }

    Garis diameter(center.getX()-Radius, center.getY(),center.getX()+Radius, center.getY());
    diameter.drawLine(buf,w);
}

void Bentuk::kapal_laut(int dir, int v, Buffer buf)
{
	if(dir == 0){		// ke kanan
		Garis g1(100+v, 275,100+v, 300);		// kiri atas - kanan atas
		Garis g2(100+v, 300,125+v, 300);		// kiri atas - kiri bawah
		Garis g3(100+v, 275, 125+v, 300);		// kiri bawah - kanan bawah
		Garis g4(100+v, 300,100+v, 325);		// kanan atas - kanan bawah
		Garis g5(50+v, 325, 150+v, 325);
		Garis g6(50+v, 325, 60+v, 350);
		Garis g7(60+v, 350, 140+v, 350);
		Garis g8(140+v, 350, 150+v, 325);
		Garis g9(150+v ,325, 160+v,300);
		Garis g10(160+v ,300, 155+v,300);
		Garis g11(155+v ,300, 145+v,325);
		
		//draw the line
		g1.drawLine(buf,putih);
		g2.drawLine(buf,putih);
		g3.drawLine(buf,putih);
		g4.drawLine(buf,putih);
		g5.drawLine(buf,putih);
		g6.drawLine(buf,putih);
		g7.drawLine(buf,putih);
		g8.drawLine(buf,putih);
		g9.drawLine(buf,putih);
		g10.drawLine(buf,putih);
		g11.drawLine(buf,putih);
		
		
		Fill fill;
		Pixel p;
		Point P(100+v,333);
		Warna hijau(0,255,0);
		Warna warna = p.getPixel(100+v,333,buf);
		fill.patternFill(P,warna,'i',buf);
		fill.patternFill(101,280,warna,'b',buf);
		//fill.FloodFill(P,warna,hijau,buf);
		
	}
	else{				// ke kiri
		Garis g1(100-v, 200, 200-v, 200);		// kiri atas - kanan atas
		Garis g2(100-v, 200, 100-v, 300);		// kiri atas - kiri bawah
		Garis g3(100-v, 300, 200-v, 300);		// kiri bawah - kanan bawah
		Garis g4(200-v, 200, 200-v, 300);		// kanan atas - kanan bawah
		
		g1.drawLine(buf,putih);
		g2.drawLine(buf,putih);
		g3.drawLine(buf,putih);
		g4.drawLine(buf,putih);
		
	}
}

void Bentuk::hapus_kapal_laut(int dir, int v, Buffer buf)
{
	if(dir == 0){		// ke kanan
		/*
		Garis s1(100+v-5, 275,100+v-5, 300);		// kiri atas - kanan atas
		Garis s2(100+v-5, 300,125+v-5, 300);		// kiri atas - kiri bawah
		Garis s3(100+v-5, 275, 125+v-5, 300);		// kiri bawah - kanan bawah
		Garis s4(100+v-5, 300,100+v-5, 325);		// kanan atas - kanan bawah
		Garis s5(50+v-5, 325, 150+v-5, 325);
		Garis s6(50+v-5, 325, 60+v-5, 350);
		Garis s7(60+v-5, 350, 140+v-5, 350);
		Garis s8(140+v-5, 350, 150+v-5, 325);
		Garis s9(150+v-5 ,325, 160+v-5,300);
		Garis s10(160+v-5 ,300, 155+v-5,300);
		Garis s11(155+v-5 ,300, 145+v-5,325);
		*/
		Garis s1(100+v, 275,100+v, 300);		// kiri atas - kanan atas
		Garis s2(100+v, 300,125+v, 300);		// kiri atas - kiri bawah
		Garis s3(100+v, 275, 125+v, 300);		// kiri bawah - kanan bawah
		Garis s4(100+v, 300,100+v, 325);		// kanan atas - kanan bawah
		Garis s5(50+v, 325, 150+v, 325);
		Garis s6(50+v, 325, 60+v, 350);
		Garis s7(60+v, 350, 140+v, 350);
		Garis s8(140+v, 350, 150+v, 325);
		Garis s9(150+v ,325, 160+v,300);
		Garis s10(160+v ,300, 155+v,300);
		Garis s11(155+v ,300, 145+v,325);
		
		//draw the shadow
		s1.drawLine(buf,hitam);
		s2.drawLine(buf,hitam);
		s3.drawLine(buf,hitam);
		s4.drawLine(buf,hitam);
		s5.drawLine(buf,hitam);
		s6.drawLine(buf,hitam);
		s7.drawLine(buf,hitam);
		s8.drawLine(buf,hitam);
		s9.drawLine(buf,hitam);
		s10.drawLine(buf,hitam);
		s11.drawLine(buf,hitam);
		
		
		Fill fill;
		Pixel p;
		Point P(100+v,333);
		Warna warna = p.getPixel(100+v,333,buf);
		fill.FloodFill(P,warna,hitam,buf);
	}
	else{				// ke kiri
		Garis s1(100+v, 200, 200+v, 200);		// kiri atas - kanan atas
		Garis s2(100+v, 200, 100+v, 300);		// kiri atas - kiri bawah
		Garis s3(100+v, 300, 200+v, 300);		// kiri bawah - kanan bawah
		Garis s4(200+v, 200, 200+v, 300);		// kanan atas - kanan bawah
		
		s1.drawLine(buf,hitam);
		s2.drawLine(buf,hitam);
		s3.drawLine(buf,hitam);
		s4.drawLine(buf,hitam);
		
	}
}

void Bentuk::boom(Buffer buf)
{
	int i;
	int plus_y = 200;
	int plus_x = 70;
	Point polygon[10];

	polygon[0].setX(81); 
	polygon[0].setY(157);
	polygon[1].setX(71);
	polygon[1].setY(147);
	polygon[2].setX(61);
	polygon[2].setY(147);
	polygon[3].setX(71);
	polygon[3].setY(137);
	polygon[4].setX(66);
	polygon[4].setY(123);
	polygon[5].setX(81);
	polygon[5].setY(127);
	polygon[6].setX(96);
	polygon[6].setY(122);
	polygon[7].setX(91);
	polygon[7].setY(137);
	polygon[8].setX(101);
	polygon[8].setY(147);
	polygon[9].setX(91);
	polygon[9].setY(147);

	for(i=0; i<10; i++) {
		if (i<9) {
			Garis g(polygon[i].getX()+plus_x, polygon[i].getY()+plus_y, 
					polygon[i+1].getX()+plus_x, polygon[i+1].getY()+plus_y);
			g.drawLine(buf,putih);
		}
		else {
			Garis g(polygon[i].getX()+plus_x, polygon[i].getY()+plus_y, 
					polygon[0].getX()+plus_x, polygon[0].getY()+plus_y);
			g.drawLine(buf,putih);
		}
	}

}

void Bentuk::pesawat(int dir, int v, Buffer buf)
{
	int y=200;
	int x = 500;	// koordinat tambahan
	if(dir == 0){		// ke kanan
		Garis g1(153+v+x, 40+y,71+v+x, 43+y);
		Garis g2(71+v+x, 43+y, 37+v+x, 58+y);
		Garis g3(37+v+x, 58+y, 32+v+x, 71+y);
		Garis g4(32+v+x, 71+y, 144+v+x, 71+y);
		Garis g5(144+v+x, 71+y, 192+v+x, 93+y);
		Garis g6(192+v+x, 93+y, 220+v+x, 94+y);
		Garis g7(220+v+x, 94+y, 203+v+x, 74+y);
		Garis g8(203+v+x, 74+y, 222+v+x, 74+y);
		Garis g9(222+v+x, 74+y, 235+v+x, 58+y);
		Garis g10(235+v+x, 58+y, 255+v+x, 28+y);		
		Garis g11(255+v+x, 28+y, 238+v+x, 24+y);
		Garis g12(238+v+x, 24+y, 210+v+x, 40+y);
		Garis g13(210+v+x, 40+y, 197+v+x, 41+y);
		Garis g14(197+v+x, 41+y, 197+v+x, 25+y);
		Garis g15(197+v+x, 25+y, 180+v+x, 25+y);	
		Garis g16(180+v+x, 25+y, 153+v+x, 40+y);

		//draw the line
		g1.drawLine(buf,putih);
		g2.drawLine(buf,putih);
		g3.drawLine(buf,putih);
		g4.drawLine(buf,putih);
		g5.drawLine(buf,putih);
		g6.drawLine(buf,putih);
		g7.drawLine(buf,putih);
		g8.drawLine(buf,putih);
		g9.drawLine(buf,putih);
		g10.drawLine(buf,putih);
		g11.drawLine(buf,putih);
		g12.drawLine(buf,putih);
		g13.drawLine(buf,putih);
		g14.drawLine(buf,putih);
		g15.drawLine(buf,putih);
		g16.drawLine(buf,putih);
		
		/*
		Fill fill;
		Pixel p;
		Warna hijau(0,255,0);
		//Warna bgpesawat = p.getPixel(644,50,buf);
		Warna bgpesawat(1,1,1);
		//fill.patternFill(644,250,bgpesawat,'b',buf);
		fill.patternFill(682,230,bgpesawat,'b',buf);
		//fill.patternFill(740,230,bgpesawat,'b',buf);
		//fill.patternFill(695,280,bgpesawat,'b',buf);
		
		//fill.FloodFill(600,60,bgpesawat,hijau,buf);
		*/
	}

	else{				// ke kiri
		Garis g1(100-v, 200, 200-v, 200);	// kiri atas - kanan atas
		Garis g2(100-v, 200, 100-v, 300);	// kiri atas - kiri bawah
		Garis g3(100-v, 300, 200-v, 300);	// kiri bawah - kanan bawah
		Garis g4(200-v, 200, 200-v, 300);	// kanan atas - kanan bawah
		
		g1.drawLine(buf,putih);
		g2.drawLine(buf,putih);
		g3.drawLine(buf,putih);
		g4.drawLine(buf,putih);
		
	}
}


void Bentuk::hapus_pesawat(int dir, int v, Buffer buf)
{

	int x = 500;	// koordinat tambahan
	if(dir == 0){		// ke kanan
		Garis g1(153+v+x+10, 40,71+v+x+10, 43);
		Garis g2(71+v+x+10, 43, 37+v+x+10, 58);
		Garis g3(37+v+x+10, 58, 32+v+x+10, 71);
		Garis g4(32+v+x+10, 71, 144+v+x+10, 71);
		Garis g5(144+v+x+10, 71, 192+v+x+10, 93);
		Garis g6(192+v+x+10, 93, 220+v+x+10, 94);
		Garis g7(220+v+x+10, 94, 203+v+x+10, 74);
		Garis g8(203+v+x+10, 74, 222+v+x+10, 74);
		Garis g9(222+v+x+10, 74, 235+v+x+10, 58);
		Garis g10(235+v+x+10, 58, 255+v+x+10, 28);		
		Garis g11(255+v+x+10, 28, 238+v+x+10, 24);
		Garis g12(238+v+x+10, 24, 210+v+x+10, 40);
		Garis g13(210+v+x+10, 40, 197+v+x+10, 41);
		Garis g14(197+v+x+10, 41, 197+v+x+10, 25);
		Garis g15(197+v+x+10, 25, 180+v+x+10, 25);	
		Garis g16(180+v+x+10, 25, 153+v+x+10, 40);

		//draw the line
		g1.drawLine(buf,hitam);
		g2.drawLine(buf,hitam);
		g3.drawLine(buf,hitam);
		g4.drawLine(buf,hitam);
		g5.drawLine(buf,hitam);
		g6.drawLine(buf,hitam);
		g7.drawLine(buf,hitam);
		g8.drawLine(buf,hitam);
		g9.drawLine(buf,hitam);
		g10.drawLine(buf,hitam);
		g11.drawLine(buf,hitam);
		g12.drawLine(buf,hitam);
		g13.drawLine(buf,hitam);
		g14.drawLine(buf,hitam);
		g15.drawLine(buf,hitam);
		g16.drawLine(buf,hitam);
		
		
		Fill fill;
		Pixel p;
		Point P(532+v,71);
		Warna warna = p.getPixel(532+v,71,buf);
		fill.FloodFill(P,warna,hitam,buf);
		
	}

	else{				// ke kiri
		Garis g1(100-v, 200, 200-v, 200);	// kiri atas - kanan atas
		Garis g2(100-v, 200, 100-v, 300);	// kiri atas - kiri bawah
		Garis g3(100-v, 300, 200-v, 300);	// kiri bawah - kanan bawah
		Garis g4(200-v, 200, 200-v, 300);	// kanan atas - kanan bawah
		
		g1.drawLine(buf,hitam);
		g2.drawLine(buf,hitam);
		g3.drawLine(buf,hitam);
		g4.drawLine(buf,hitam);
		
	}
}

void Bentuk::baling(Point center, Buffer buf) {
	int radius = 3;
	circle(center,radius, buf, putih); 

	//kuadran 1
	Point atas1(center.getX()+30,center.getY()-40);
	Point bawah1(center.getX()+50,center.getY()-15);
	Point jbawah1(center.getX()+radius,center.getY());
	Point jatas1(center.getX(),center.getY()-radius);
	Garis g11(atas1,bawah1); g11.drawLine(buf,putih);
	Garis g21(atas1,jatas1); g21.drawLine(buf,putih);
	Garis g31(bawah1,jbawah1); g31.drawLine(buf,putih);

	//kuadran 2
	Point atas2(center.getX()-30,center.getY()-40);
	Point bawah2(center.getX()-50,center.getY()-15);
	Point jbawah2(center.getX()-radius,center.getY());
	Point jatas2(center.getX(),center.getY()-radius);
	Garis g12(atas2,bawah2); g12.drawLine(buf,putih);
	Garis g22(atas2,jatas2); g22.drawLine(buf,putih);
	Garis g32(bawah2,jbawah2); g32.drawLine(buf,putih);

	//kuadran 3
	Point atas3(center.getX()-30,center.getY()+40);
	Point bawah3(center.getX()-50,center.getY()+15);
	Point jbawah3(center.getX()-radius,center.getY());
	Point jatas3(center.getX(),center.getY()+radius);
	Garis g13(atas3,bawah3); g13.drawLine(buf,putih);
	Garis g23(atas3,jatas3); g23.drawLine(buf,putih);
	Garis g33(bawah3,jbawah3); g33.drawLine(buf,putih);

	//kuadran 4
	Point atas4(center.getX()+30,center.getY()+40);
	Point bawah4(center.getX()+50,center.getY()+15);
	Point jbawah4(center.getX()+radius,center.getY());
	Point jatas4(center.getX(),center.getY()+radius);
	Garis g14(atas4,bawah4); g14.drawLine(buf,putih);
	Garis g24(atas4,jatas4); g24.drawLine(buf,putih);
	Garis g34(bawah4,jbawah4); g34.drawLine(buf,putih);

}

void Bentuk::parasut(Point center_p, int radius_p, Buffer buf) {
	setengah_lingkaran(center_p,radius_p,buf);
	//tali parasut
	Point pkanan(center_p.getX()+radius_p,center_p.getY());
	Point pkiri(center_p.getX()-radius_p,center_p.getY());
	Point pbawah(center_p.getX(),center_p.getY()+radius_p);
	Garis gkanan(pkanan,pbawah); gkanan.drawLine(buf,putih);
	Garis gkiri(pkiri,pbawah); gkiri.drawLine(buf,putih);
	//orang
	int rkepala = radius_p/8;
	Point ckepala(pbawah.getX(),pbawah.getY()-rkepala);
	Point tanganka(pbawah.getX()+radius_p/4,pbawah.getY()+radius_p/4);
	Point tanganki(pbawah.getX()-radius_p/4,pbawah.getY()+radius_p/4);
	Point badan(pbawah.getX(),pbawah.getY()+radius_p/2);
	Point kakika(badan.getX()+radius_p/4,badan.getY()+radius_p/4);
	Point kakiki(badan.getX()-radius_p/4,badan.getY()+radius_p/4);
	circle(ckepala,rkepala,buf,putih);
	Garis tkanan(pbawah,tanganka); tkanan.drawLine(buf,putih);
	Garis tkiri(pbawah,tanganki); tkiri.drawLine(buf,putih);
	Garis gbadan(pbawah,badan); gbadan.drawLine(buf,putih);
	Garis kkanan(badan,kakika); kkanan.drawLine(buf,putih);
	Garis kkiri(badan,kakiki); kkiri.drawLine(buf,putih);

}