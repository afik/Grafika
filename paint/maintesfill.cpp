#include <iostream>
#include "garis.h"
#include "fill.h"
#include "bentuk.h"
#include "pixel.h"

using namespace std;

int main()
{
	Buffer buf;
	Bentuk bentuk;
	Fill fill;
	Warna warna(1,1,1);
	
	bentuk.circle(400,400,100,buf,*Warna::putih());
	fill.FloodFill(400,400,warna,*Warna::merah(),buf);

	usleep(1000000);

	fill.FloodFill(400,400,*Warna::merah(),*Warna::hitam(),buf);
	
	buf.closeBuffer();
	return 0;
}
