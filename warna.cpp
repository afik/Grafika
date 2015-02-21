#include "warna.h"

Warna* Warna::wputih = new Warna();
Warna* Warna::whitam = new Warna(0,0,0);
Warna* Warna::wmerah = new Warna(255,0,0);
Warna* Warna::whijau = new Warna(0,255,0);
Warna* Warna::wbiru = new Warna(0,0,255);
Warna* Warna::wkuning = new Warna(255,255,0);
Warna* Warna::wcoklat = new Warna(102,51,0);
Warna* Warna::wungu = new Warna(102,0,102);
Warna* Warna::woranye = new Warna(255,128,0);


Warna::Warna()
{
	R = 255;
	G = 255;
	B = 255;
}

Warna::Warna(int R, int G, int B)
{
	this->R = R;
	this->G = G;
	this->B = B;
}

Warna::~Warna(){}

void Warna::setRed(int R)
{
	this->R = R;
}

void Warna::setGreen(int G)
{
	this->G = G;
}

void Warna::setBlue(int B)
{
	this->B = B;
}

int Warna::getRed()
{
	return R;
}

int Warna::getGreen()
{
	return G;
}

int Warna::getBlue()
{
	return B;
}
