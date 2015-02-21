#include <iostream>
#include "pixel.h"
#include "kapal.h"
#include "helikopter.h"

using namespace std;

int main()
{
	Buffer buff;
	Kapal destroyer;
	Helikopter falcon;
	int i=1;
	
	system("clear");
	
	while(i<1000)
	{
		//destroyer.drawKapal(buff);
		destroyer.clearKapal(buff);
		destroyer.setVelocity(i);
		destroyer.drawKapal(buff);
		
		falcon.clearHeli(buff);
		falcon.setVelocity(i);
		falcon.drawHeli(buff);
		
		i++;
		usleep(5000);
	}

	buff.closeBuffer();
	return 0;
}
