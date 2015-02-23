#include "peluru.h"

Peluru::Peluru(int posisiX, int posisiY)		// ctor
{
		titikPusatPeluru.setX(posisiX);
		titikPusatPeluru.setY(posisiY);
		radianPeluru = 10;
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
	// Definisikan titik ujung peluru
	Point titikKiriAtas (titikPusatPeluru.getX()-radianPeluru, titikPusatPeluru.getY()-radianPeluru);
	Point titikKiriBawah (titikPusatPeluru.getX()-radianPeluru, titikPusatPeluru.getY()+radianPeluru);
	Point titikKananAtas (titikPusatPeluru.getX()+radianPeluru, titikPusatPeluru.getY()-radianPeluru);
	Point titikKananBawah (titikPusatPeluru.getX()+radianPeluru, titikPusatPeluru.getY()+radianPeluru);
				
	// Buat peluru berbentuk persegi (asumsi sementara) dari titik ujung peluru
	Garis garisPeluru1(titikKiriAtas,titikKananAtas); 
	Garis garisPeluru2(titikKiriAtas,titikKiriBawah);
	Garis garisPeluru3(titikKananAtas,titikKananBawah);
	Garis garisPeluru4(titikKananBawah,titikKiriBawah);
	
	garisPeluru1.drawLine(frameBuffer,warnaGarisPeluru);
	garisPeluru2.drawLine(frameBuffer,warnaGarisPeluru);
	garisPeluru3.drawLine(frameBuffer,warnaGarisPeluru);
	garisPeluru4.drawLine(frameBuffer,warnaGarisPeluru);
}
void Peluru::clearPeluru()  								// prosedur untuk menghilangkan gambar peluru dari layar
{
	// Definisikan titik ujung peluru
	Point titikKiriAtas (titikPusatPeluru.getX()-radianPeluru, titikPusatPeluru.getY()-radianPeluru);
	Point titikKiriBawah (titikPusatPeluru.getX()-radianPeluru, titikPusatPeluru.getY()+radianPeluru);
	Point titikKananAtas (titikPusatPeluru.getX()+radianPeluru, titikPusatPeluru.getY()-radianPeluru);
	Point titikKananBawah (titikPusatPeluru.getX()+radianPeluru, titikPusatPeluru.getY()+radianPeluru);
	
	// Set warna peluru jadi transparan
	warnaGarisPeluru.setRed(0);
	warnaGarisPeluru.setBlue(0);
	warnaGarisPeluru.setGreen(0);
				
	// Gambar (seolah-olah) peluru dengan warna transparan
	Garis garisPeluru1(titikKiriAtas,titikKananAtas); 
	Garis garisPeluru2(titikKiriAtas,titikKiriBawah);
	Garis garisPeluru3(titikKananAtas,titikKananBawah);
	Garis garisPeluru4(titikKananBawah,titikKiriBawah);
	
	garisPeluru1.drawLine(frameBuffer,warnaGarisPeluru);
	garisPeluru2.drawLine(frameBuffer,warnaGarisPeluru);
	garisPeluru3.drawLine(frameBuffer,warnaGarisPeluru);
	garisPeluru4.drawLine(frameBuffer,warnaGarisPeluru);
}
void Peluru::luncurkanPeluru(int posisiOrdinatPesawat)		// prosedur untuk meluncurkan peluru, asumsi gerak peluru konstan
{
	system("clear");
	while (titikPusatPeluru.getY() >= posisiOrdinatPesawat) {
		clearPeluru();
		setAbsisTitikPusatPeluru (titikPusatPeluru.getX() + 100);
		setOrdinatTitikPusatPeluru (titikPusatPeluru.getY() - 100);
		warnaGarisPeluru.setRed(255);
		warnaGarisPeluru.setGreen(255);
		warnaGarisPeluru.setBlue(255);
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
