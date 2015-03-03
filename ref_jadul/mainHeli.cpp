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
	Pixel p;
	Fill fill;

	Point po(738,224);
	Point p1(200,200);
	bentuk.pesawat(0,0,buf);
	bentuk.baling(po,buf);
	bentuk.parasut(p1,40,buf);

	buf.closeBuffer();
	return 0;
}
