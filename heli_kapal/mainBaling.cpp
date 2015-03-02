#include <iostream>
#include "pixel.h"
#include "baling.h"

using namespace std;

int main()
{
	Buffer buff;
	Baling baling;
	int i=1;
	char x;
	int sudut = 0;
	//system("clear");
	Point center(200,200);
	while(i<1000 && center.getX() < 1300)
	{
	// 	//destroyer.drawKapal(buff);
		baling.clearBaling(sudut-10,buff);
		center.setX(center.getX()+10);
		center.setY(center.getY()+10);
		baling.setCenter(center);
		baling.rotasiBaling(sudut,buff);
		i++;
		sudut+=10;
		usleep(30000);
	}
		cout << "Nih!! \n";

	buff.closeBuffer();
	return 0;
}
