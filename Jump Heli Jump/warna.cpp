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

Warna* Warna::wbirutoska = new Warna(102,204,255);
Warna* Warna::wpink = new Warna(255,153,153);
Warna* Warna::wbirulangit = new Warna(102,204,204);
Warna* Warna::wsoftpink = new Warna(255,204,204);
Warna* Warna::worenmuda = new Warna(255,204,102);
Warna* Warna::wabu = new Warna(204,204,153);
Warna* Warna::wviolet = new Warna(204,153,204);
Warna* Warna::wshockpink = new Warna(255,51,102);

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

Warna::Warna(const Warna& w)
{
	this->R = w.R;
	this->G = w.G;
	this->B = w.B;
}

Warna& Warna::operator=(const Warna& w)
{
	this->R = w.R;
	this->G = w.G;
	this->B = w.B;
	return *this;
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
