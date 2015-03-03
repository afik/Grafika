#include <iostream>
#include "pixel.h"
#include "helikopter.h"

using namespace std;

int main()
{
	Buffer buff;
	Helikopter falcon;
	int i=1;
	
	system("clear");
	
	while(i<1000)
	{
		//destroyer.drawKapal(buff);
		falcon.clearHeli(buff);
		falcon.drawHeli(buff);
		falcon.setVelocity(i);
		i++;
		usleep(5000);
	}

	buff.closeBuffer();
	return 0;
}
