#include "persegi.h"
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
	Persegi p;
	p.setPanjang(100);
	p.setLebar(100);
	p.setKiriAtas(P);

	p.drawPersegi(warna, buf);
	p.clearPersegi(buf);
	return 0;
}