#include <iostream>
#include "pixel.h"
#include "kapal.h"
#include "helikopter.h"
#include "baling.h"
#include "peluru.h"
#include "parasut.h"
#include "bentuk.h"
#include "ledakan.h"

using namespace std;

void bolaPantul(Point center, int Radius);

int main()
{
	Buffer buff;
	Kapal destroyer;			// kapal
	Helikopter falcon, falconDestroy;			// helikopter
	Baling baling;				// baling-baling
	Parasut para;
	Ledakan ledakan;
	
	Bentuk bentuk;				// roda baling-baling
	int tempx, tempy, x, y, j;		// untuk pantulan
	int t= 300, c = 1;
	
	int vi=1;
	int vj=1;
	bool kena = false;			// cek collision
	int sudut = 0;				// baling-baling
	Point center, collision, posPara;
	system("clear");
	
	Peluru misil(200,300);
	para.setRadius(30);
	while(1)
	{
		
		/** kapal */
		destroyer.clearKapal(buff);
		destroyer.setVelocity(vi);
		destroyer.drawKapal(buff);
		/** end of kapal */
		
		if (!kena) {
			/** helikopter */
			falcon.clearHeli(buff,1);
			falcon.setVelocity(vi);
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
				misil.setAbsisTitikPusatPeluru (destroyer.getAnchorP2().getX()-30);
				misil.setOrdinatTitikPusatPeluru (destroyer.getAnchorP2().getY()-30);
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
					
					// hapus peluru
					misil.clearPeluru();
					
					// hapus helikopter
					falcon.clearHeli(buff,1);
					falconDestroy.setP1(falcon.getAnchorP1());
					falconDestroy.setP2(falcon.getAnchorP2());
					
					// hapus baling-baling
					baling.clearBaling(sudut-100,buff);
					
					//set parasut
					posPara.setX((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
					posPara.setY(falcon.getAnchorP2().getY());
					para.setPosition(posPara);
					
					//ledakan
					ledakan.setAbsisTitikPusatLedakan((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2);
					ledakan.setOrdinatTitikPusatLedakan(falcon.getAnchorP2().getY());
					ledakan.meledak();
				}
		}
		else {	// kena = true
			falconDestroy.clearpecahHeli(buff);
			falconDestroy.setVelocity(vj);
			falconDestroy.pecahHeli(buff);
			
			/** Parasut */
			para.clearParasut(buff);
			para.setVelocity((vj*0.5));
			para.drawParasut(buff);
			/** end of parasut */
			
			/** Baling-baling */
			center.setX(((falcon.getAnchorP1().getX()+falcon.getAnchorP2().getX())/2)-vj);
			center.setY(falcon.getAnchorP1().getY()+(vj*2));
			
			baling.clearBaling(sudut-10,buff);
			center.setX(center.getX());
			center.setY(center.getY());
			baling.setCenter(center);
			baling.rotasiBaling(sudut,buff);
			sudut+=10;
			/** Baling-baling */
			
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
			
			if(y<320)
				y = y + (c?15: -15);
			if (y==center.getY()) {
				c = 1;
			}
			
			vj+=1;
		}
		vi+=5;	// pertambahan kecepatan
		
		usleep(30000);
	}

	buff.closeBuffer();
	return 0;
}
