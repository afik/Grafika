#include <iostream>
#include "pixel.h"
#include "kapal.h"
#include "helikopter.h"
#include "baling.h"
#include "peluru.h"
#include "bentuk.h"

using namespace std;

void bolaPantul();

int main()
{
	Buffer buff;
	char c;
	Kapal destroyer;
	Helikopter falcon;
	Baling baling;
	
	int i=1;
	bool kena = false;
	//baling
	int sudut = 0;
	Point center;
	system("clear");
	
	Peluru misil(200,300);
	//misil.luncurkanPeluru(100);
	
	while(!kena)
	{
		//destroyer.drawKapal(buff);
		destroyer.clearKapal(buff);
		destroyer.setVelocity(i);
		destroyer.drawKapal(buff);
		
		
		falcon.clearHeli(buff,1);
		falcon.setVelocity(i);
		falcon.drawHeli(buff,1);
		
		//peluru
		if(misil.getOrdinatTitikPusatPeluru() > falcon.getAnchorP2().getY()){
			misil.clearPeluru();
			misil.setAbsisTitikPusatPeluru (misil.getAbsisTitikPusatPeluru() + 1);
			misil.setOrdinatTitikPusatPeluru (misil.getOrdinatTitikPusatPeluru() - 1);
			misil.drawPeluru();
		}
		else
		{
			misil.clearPeluru();
			misil.setAbsisTitikPusatPeluru (destroyer.getAnchorP2().getY());
			misil.setOrdinatTitikPusatPeluru (300);
			misil.drawPeluru();
		}
		
		//set posisi baling"
		center.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
		center.setY(falcon.getAnchorP1().getY()-20);
		
		baling.clearBaling(sudut-10,buff);
		center.setX(center.getX()-1);
		center.setY(center.getY());
		baling.setCenter(center);
		baling.rotasiBaling(sudut,buff);
		i++;
		sudut+=10;
		
		if(i==1000){
			kena = true;
		}
		
		usleep(5000);
	}
	
	bolaPantul();

	buff.closeBuffer();
	return 0;
}

void bolaPantul()
{
	Buffer buff;
	Warna warna;
	Pixel pixel;
	Bentuk bentuk;
	Point posisi(300,300);
	Point posisi2(300,400);
	int tempx=40, tempy=200, x,y=200,j;
	int t= 400, c = 1;

	for (x = 40; x<602; x++) {
		bentuk.circle(tempx,tempy,20,buff,*Warna::hitam());
		bentuk.circle(x,y,20,buff,*Warna::kuning());
		
		if(y >= 400) {
			c = 0;
			t -= 20;
		}
		if (y <=400-t) {
			c=1;
		}
		tempy = y;
		tempx = x;
		y = y + (c?15: -15);
		usleep(25000);
	}
	
	buff.closeBuffer();
}
