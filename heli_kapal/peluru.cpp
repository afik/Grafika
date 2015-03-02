#include "peluru.h"

Peluru::Peluru(int posisiX, int posisiY)		// ctor
{
		titikPusatPeluru.setX(posisiX);
		titikPusatPeluru.setY(posisiY);
		radianPeluru = 5;
}
Peluru::Peluru()											// ctor default
{
		radianPeluru = 2;
}
Peluru::~Peluru()											// dtor
{
		
}

void Peluru::drawPeluru()									// prosedur untuk menggambar peluru di titik pusat peluru
{	
	warnaGarisPeluru.setRed(255);
	warnaGarisPeluru.setGreen(255);
	warnaGarisPeluru.setBlue(255);
	Bentuk circleDrawer;
	circleDrawer.circle(titikPusatPeluru, radianPeluru, frameBuffer, warnaGarisPeluru);
}
void Peluru::clearPeluru()  								// prosedur untuk menghilangkan gambar peluru dari layar
{
	warnaGarisPeluru.setRed(0);
	warnaGarisPeluru.setGreen(0);
	warnaGarisPeluru.setBlue(0);
	Bentuk circleDrawer;
	circleDrawer.circle(titikPusatPeluru, radianPeluru, frameBuffer, warnaGarisPeluru);
}
void Peluru::luncurkanPeluru(int posisiOrdinatPesawat)		// prosedur untuk meluncurkan peluru, asumsi gerak peluru konstan
{
	system("clear");
	while (titikPusatPeluru.getY() >= posisiOrdinatPesawat) {
		clearPeluru();
		setAbsisTitikPusatPeluru (titikPusatPeluru.getX() + 100);
		setOrdinatTitikPusatPeluru (titikPusatPeluru.getY() - 100);
		drawPeluru();
		usleep(100000);
	}
}

void Peluru::setAbsisTitikPusatPeluru (int newAbsis)
{
		titikPusatPeluru.setX(newAbsis);
}
void Peluru::setOrdinatTitikPusatPeluru (int newOrdinat)
{
		titikPusatPeluru.setY(newOrdinat);
}
void Peluru::setRadianPeluru (int newRadiant) 
{
		radianPeluru = newRadiant;
}
int Peluru::getAbsisTitikPusatPeluru()
{
		return titikPusatPeluru.getX();
}
int Peluru::getOrdinatTitikPusatPeluru()
{
		return titikPusatPeluru.getY();
}
int Peluru::getRadianPeluru()
{
		return radianPeluru;
}
