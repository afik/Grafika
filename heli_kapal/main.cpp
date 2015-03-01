#include <iostream>
#include "pixel.h"
#include "kapal.h"
#include "helikopter.h"
#include "baling.h"
#include "peluru.h"
#include "parasut.h"
#include "bentuk.h"

using namespace std;

void bolaPantul(Point center, int Radius);

int main()
{
	Buffer buff;
	char c;
	Kapal destroyer;
	Helikopter falcon;
	Baling baling;
	Parasut para;
	
	int i=1;
	bool kena = false;
	//baling
	int sudut = 0;
	Point center, collision;
	system("clear");
	
	Peluru misil(200,300);
	para.setRadius(30);
	while(1)
	{
		destroyer.clearKapal(buff);
		if (!kena) {
			/** kapal */
			destroyer.setVelocity(i);
			destroyer.drawKapal(buff);
			/** end of kapal */
			
			/** helikopter */
			falcon.clearHeli(buff,1);
			falcon.setVelocity(i);
			falcon.drawHeli(buff,1);
			
			/* set posisi baling" */
			center.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
			center.setY(falcon.getAnchorP1().getY()-20);
			
			baling.clearBaling(sudut-10,buff);
			center.setX(center.getX()-1);
			center.setY(center.getY());
			baling.setCenter(center);
			baling.rotasiBaling(sudut,buff);
			sudut+=10;
			/** end of helikopter */
			
			i++;	// pertambahan kecepatan
			
			/** Peluru */
			if(misil.getOrdinatTitikPusatPeluru() > falcon.getAnchorP2().getY()){
				misil.clearPeluru();
				misil.setAbsisTitikPusatPeluru (misil.getAbsisTitikPusatPeluru() + 1);
				misil.setOrdinatTitikPusatPeluru (misil.getOrdinatTitikPusatPeluru() - 1);
				misil.drawPeluru();
			}
			else
			{
				misil.clearPeluru();
				misil.setAbsisTitikPusatPeluru (destroyer.getAnchorP2().getX());
				misil.setOrdinatTitikPusatPeluru (destroyer.getAnchorP2().getY());
				misil.drawPeluru();
			}
			/** end of peluru */
			
			collision.setX(falcon.getAnchorP1().getX()-20);
			collision.setY(falcon.getAnchorP2().getY()+20);
			/*printf("misil : %d %d, collision : %d %d, anchor2 : %d %d\n", 
					misil.getAbsisTitikPusatPeluru(),
					misil.getOrdinatTitikPusatPeluru(),
					collision.getX(), collision.getY(), falcon.getAnchorP2().getX(), falcon.getAnchorP2().getY());*/
			if ((misil.getOrdinatTitikPusatPeluru() < collision.getY()) && 
				((misil.getAbsisTitikPusatPeluru() > collision.getX())&&(misil.getAbsisTitikPusatPeluru() < falcon.getAnchorP2().getX()))) {
				//	kena = true;
				}
		}
		else {
			printf("kena\n");
			
			break;
		}
		
		usleep(5000);
	}
	
	bolaPantul(baling.getCenter(), 10);

	buff.closeBuffer();
	return 0;
}

void bolaPantul(Point center, int Radius)
{
	Buffer buff;
	Warna warna;
	Pixel pixel;
	Bentuk bentuk;
	int tempx=center.getX(), tempy=center.getY(), x,y=center.getY(),j;
	int t= 300, c = 1;

	for (x = center.getX(); x<center.getX()+200; x++) {
		bentuk.circle(tempx,tempy,Radius,buff,*Warna::hitam());
		bentuk.circle(x,y,Radius,buff,*Warna::kuning());
		
		if(y >= 300) {
			c = 0;
			t -= 30;
		}
		if (y <=300-t) {
			c=1;
		}
		tempy = y;
		tempx = x;
		
		y = y + (c?15: -15);
		if (y==center.getY()) {
			c = 1;
		}
		usleep(25000);
	}
	
	buff.closeBuffer();
}
