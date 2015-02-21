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
	
	while(i<1000)
	{
	// 	//destroyer.drawKapal(buff);
		baling.clearBaling(sudut-10,buff);
		baling.rotasiBaling(sudut,buff);
		i++;
		sudut+=10;
		usleep(30000);
	}
		cout << "Nih!! \n";

	buff.closeBuffer();
	return 0;
}
