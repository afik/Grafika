#include "lingkaran.h"
#include "point.h"
#include "buffer.h"
#include "warna.h"
#include "pixel.h"
#include <iostream>

using namespace std;

int main() {
	Warna warna;
	Buffer buf;
	Point P(500,500);
	Lingkaran p;
	p.setRadius(100);
	
	p.setCenter(P);

	p.drawLingkaran(warna, buf);
	//p.clearLingkaran(buf);
	return 0;
}
