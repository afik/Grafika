#include <iostream>
#include "pixel.h"
#include "kapal.h"

using namespace std;

int main()
{
	Buffer buff;
	Kapal destroyer;
	int i=1;
	
	system("clear");
	
	while(i<1000)
	{
		//destroyer.drawKapal(buff);
		destroyer.clearKapal(buff);
		destroyer.setVelocity(i);
		destroyer.drawKapal(buff);
		
		i++;
		usleep(5000);
	}

	buff.closeBuffer();
	return 0;
}
