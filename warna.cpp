#include "warna.h"

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
