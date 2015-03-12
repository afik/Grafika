#include "ledakan.h"

Ledakan::Ledakan(int posisiX, int posisiY)					// ctor
{
		titikPusatLedakan.setX(posisiX);
		titikPusatLedakan.setY(posisiY);
		radiusLedakan = 30;
}
Ledakan::Ledakan()											// ctor default
{
		radiusLedakan = 30;
}
Ledakan::~Ledakan()											// dtor
{
		
}

void Ledakan::drawLedakan()									// prosedur untuk menggambar ledakan sesaat
{
	// Buat titik-titik yang terlibat dalam pentagon ledakan
	Point titik1Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(0.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(0.0));
	Point titik2Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(60.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(60.0));
	Point titik3Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(120.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(120.0));
	Point titik4Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(180.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(180.0));
	Point titik5Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(240.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(240.0));
	Point titik6Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(300.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(300.0));
	
	Point titik1Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(-30.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(-30.0));
	Point titik2Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(30.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(30.0));
	Point titik3Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(90.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(90.0));
	Point titik4Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(150.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(150.0));
	Point titik5Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(210.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(210.0));
	Point titik6Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(270.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(270.0));
	
	// Gambar garis-garis yang menghubungkan titik-titik pentagon ledakan di atas
	Warna warnaGarisLedakan (255,255,255); // warna putih
	
	Garis sisi1Polygon1 (titik1Polygon1, titik2Polygon1); sisi1Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi2Polygon1 (titik2Polygon1, titik3Polygon1); sisi2Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi3Polygon1 (titik3Polygon1, titik4Polygon1); sisi3Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi4Polygon1 (titik4Polygon1, titik5Polygon1); sisi4Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi5Polygon1 (titik5Polygon1, titik6Polygon1); sisi5Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi6Polygon1 (titik6Polygon1, titik1Polygon1); sisi6Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	
	Garis sisi1Polygon2 (titik1Polygon2, titik2Polygon2); sisi1Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi2Polygon2 (titik2Polygon2, titik3Polygon2); sisi2Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi3Polygon2 (titik3Polygon2, titik4Polygon2); sisi3Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi4Polygon2 (titik4Polygon2, titik5Polygon2); sisi4Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi5Polygon2 (titik5Polygon2, titik6Polygon2); sisi5Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi6Polygon2 (titik6Polygon2, titik1Polygon2); sisi6Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
}
void Ledakan::clearLedakan()											// prosedur untuk menghapus gambar ledakan sesaat
{
	// Buat titik-titik yang terlibat dalam pentagon ledakan
	Point titik1Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(0.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(0.0));
	Point titik2Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(60.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(60.0));
	Point titik3Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(120.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(120.0));
	Point titik4Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(180.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(180.0));
	Point titik5Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(240.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(240.0));
	Point titik6Polygon1 (titikPusatLedakan.getX() + absisHasilTrigonometri(300.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(300.0));
	
	Point titik1Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(-30.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(-30.0));
	Point titik2Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(30.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(30.0));
	Point titik3Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(90.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(90.0));
	Point titik4Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(150.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(150.0));
	Point titik5Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(210.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(210.0));
	Point titik6Polygon2 (titikPusatLedakan.getX() + absisHasilTrigonometri(270.0), 
						titikPusatLedakan.getY() + ordinatHasilTrigonometri(270.0));
	
	// Gambar garis-garis yang menghubungkan titik-titik pentagon ledakan di atas
	Warna warnaGarisLedakan (0,0,0); // warna transparan
	
	Garis sisi1Polygon1 (titik1Polygon1, titik2Polygon1); sisi1Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi2Polygon1 (titik2Polygon1, titik3Polygon1); sisi2Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi3Polygon1 (titik3Polygon1, titik4Polygon1); sisi3Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi4Polygon1 (titik4Polygon1, titik5Polygon1); sisi4Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi5Polygon1 (titik5Polygon1, titik6Polygon1); sisi5Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi6Polygon1 (titik6Polygon1, titik1Polygon1); sisi6Polygon1.drawLine(frameBuffer, warnaGarisLedakan);
	
	Garis sisi1Polygon2 (titik1Polygon2, titik2Polygon2); sisi1Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi2Polygon2 (titik2Polygon2, titik3Polygon2); sisi2Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi3Polygon2 (titik3Polygon2, titik4Polygon2); sisi3Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi4Polygon2 (titik4Polygon2, titik5Polygon2); sisi4Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi5Polygon2 (titik5Polygon2, titik6Polygon2); sisi5Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
	Garis sisi6Polygon2 (titik6Polygon2, titik1Polygon2); sisi6Polygon2.drawLine(frameBuffer, warnaGarisLedakan);
}
void Ledakan::meledak()															// prosedur untuk menggambar ledakan secara keseluruh
{
		system("clear");
		for (int i=1;i<5;i++) {
				clearLedakan();
				setRadiusLedakan(this->getRadiusLedakan()+(i*10));
				drawLedakan();
				usleep(100000);
		}
		//clearLedakan();
}
int Ledakan::absisHasilTrigonometri(double degrees)						// fungsi untuk menghitung proyeksi radius ledakan pada sumbu X dengan sudut degrees
{
		return (radiusLedakan * cos (degrees * PIx / 180));
}
int Ledakan::ordinatHasilTrigonometri(double degrees)					// fungsi untuk menghitung proyeksi radius ledakan pada sumbu Y dengan sudut degrees
{
		return (radiusLedakan * sin (degrees * PIx / 180));
}

void Ledakan::setAbsisTitikPusatLedakan (int newAbsis) 
{
		titikPusatLedakan.setX(newAbsis);
}
void Ledakan::setOrdinatTitikPusatLedakan (int newOrdinat) 
{
		titikPusatLedakan.setY(newOrdinat);
}
void Ledakan::setRadiusLedakan(int newRadius) 
{
		radiusLedakan = newRadius;
}
int Ledakan::getAbsisTitikPusatLedakan()
{
		return titikPusatLedakan.getX();
}
int Ledakan::getOrdinatTitikPusatLedakan()
{
		return titikPusatLedakan.getY();
}
int Ledakan::getRadiusLedakan()
{
		return radiusLedakan;
}
