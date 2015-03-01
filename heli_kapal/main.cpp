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
	Kapal destroyer;			// kapal
	Helikopter falcon;			// helikopter
	Baling baling;				// baling-baling
	Parasut para;
	
	Bentuk bentuk;				// roda baling-baling
	int tempx, tempy, x, y, j;		// untuk pantulan
	int t= 300, c = 1;
	
	int i=1;
	bool kena = false;			// cek collision
	int sudut = 0;				// baling-baling
	Point center, collision;
	system("clear");
	
	Peluru misil(200,300);
	para.setRadius(30);
	while(1)
	{
		/** kapal */
		destroyer.clearKapal(buff);
		destroyer.setVelocity(i);
		destroyer.drawKapal(buff);
		/** end of kapal */
		
		if (!kena) {
			/** helikopter */
			falcon.clearHeli(buff,1);
			falcon.setVelocity(i);
			falcon.drawHeli(buff,1);
			
			/* set posisi baling" */
			center.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
			center.setY(falcon.getAnchorP1().getY()-20);
			
			baling.clearBaling(sudut-100,buff);
			center.setX(center.getX()-1);
			center.setY(center.getY());
			baling.setCenter(center);
			baling.rotasiBaling(sudut,buff);
			sudut+=100;
			/** end of helikopter */			
			
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
			
			/** set collision */
			collision.setX(falcon.getAnchorP1().getX()-20);
			collision.setY(falcon.getAnchorP2().getY()+20);
			if ((misil.getOrdinatTitikPusatPeluru() < collision.getY()) && 
				((misil.getAbsisTitikPusatPeluru() > collision.getX())&&(misil.getAbsisTitikPusatPeluru() < falcon.getAnchorP2().getX()))) {
					kena = true;
					tempx = baling.getCenter().getX();
					tempy = baling.getCenter().getY();
					y = baling.getCenter().getY();
					x = baling.getCenter().getX();
					misil.clearPeluru();
				}
		}
		else {	// kena = true
			bentuk.circle(tempx, tempy, baling.getRadius(), buff, *Warna::hitam());
			bentuk.circle(x, y, baling.getRadius(), buff, *Warna::kuning());
			
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
			x++;
		}
		i+=5;	// pertambahan kecepatan
		
		usleep(30000);
	}

	buff.closeBuffer();
	return 0;
}
