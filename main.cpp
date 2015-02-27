#include <iostream>
#include "pixel.h"
#include "kapal.h"
#include "helikopter.h"

using namespace std;

int main()
{
	Buffer buff;
	char c;
	Kapal destroyer;
	Helikopter falcon;
	int i=1;
	
	system("clear");
	
	//falcon.drawHeli(buff,2);
	while(i<1000)
	{
		//destroyer.drawKapal(buff);
		destroyer.clearKapal(buff);
		destroyer.setVelocity(i);
		destroyer.drawKapal(buff);
		
		falcon.clearJatuh(buff,1);
		falcon.setVelocity(i);
		falcon.drawJatuh(buff,1);
		
		i++;
		usleep(5000);
	}

	buff.closeBuffer();
	return 0;
}
