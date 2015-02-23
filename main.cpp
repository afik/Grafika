#include <iostream>
#include "pixel.h"
#include "kapal.h"
#include "helikopter.h"
#include "baling.h"

using namespace std;

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
	
	while(!kena)
	//falcon.drawHeli(buff,2);
	{
		//destroyer.drawKapal(buff);
		destroyer.clearKapal(buff);
		destroyer.setVelocity(i);
		destroyer.drawKapal(buff);
		
		falcon.clearHeli(buff,1);
		falcon.setVelocity(i);
		falcon.drawHeli(buff,1);
		
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
		usleep(5000);
	}

	buff.closeBuffer();
	return 0;
}
