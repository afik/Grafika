#include "polygon.h"

Polygon::Polygon() {
	centrePolygon.setX(200);
	centrePolygon.setY(200);
}

Polygon::Polygon(Point centrePolygon) {
	this->centrePolygon = centrePolygon;
}								// assign point 2D alas

Polygon::Polygon(const Polygon& poly) {
	this->centrePolygon = poly.centrePolygon;
	this->kumpulanPointAlas = poly.kumpulanPointAlas;
}

Polygon& Polygon::operator=(const Polygon& poly) {
	this->centrePolygon = poly.centrePolygon;
	this->kumpulanPointAlas = poly.kumpulanPointAlas;
	return *this;
}

Polygon::~Polygon() {

}

void Polygon::drawPolygon(Buffer buff, Warna w) {

	for(int i=0; i<jumlahTitikPolygon(); i++)
	{
		if(i<jumlahTitikPolygon()-1)
		{
			Garis g(kumpulanPointAlas[i].getX(), kumpulanPointAlas[i].getY(),
					kumpulanPointAlas[i+1].getX(), kumpulanPointAlas[i+1].getY());
			g.drawLine(buff, w);
		}
		else
		{
			Garis g(kumpulanPointAlas[i].getX(), kumpulanPointAlas[i].getY(),
					kumpulanPointAlas[0].getX(), kumpulanPointAlas[0].getY());
			g.drawLine(buff, w);
		}
	}
}										// Gambar alas polygon 2D

void Polygon::drawPolygon3D(Buffer buff, int height) {

}

void Polygon::addPoint(vector<Point> listPoint) {
	kumpulanPointAlas = listPoint;
}

void Polygon::clearPolygon() {
	Buffer buff;
	drawPolygon(buff, *Warna::hitam());
}										// Hapus polygon 

void Polygon::fillPolygonColor() {

}								// Isi polygon dengan warna tertentu

void Polygon::fillPolygonPattern() {

}									// Isi polygon dengan pattern tertentu

void Polygon::moveUp() {
	clearPolygon();
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setY(kumpulanPointAlas[i].getY()-5);
	}
	centrePolygon.setY(centrePolygon.getY()-5);
}											// Geser polygon 2D/3D ke atas

void Polygon::moveDown() {
	clearPolygon();
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setY(kumpulanPointAlas[i].getY()+5);
	}
	centrePolygon.setY(centrePolygon.getY()+5);
}											// Geser polygon 2D/3D ke bawah

void Polygon::moveLeft() {
	clearPolygon();
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setX(kumpulanPointAlas[i].getX()-5);
	}
	centrePolygon.setX(centrePolygon.getX()-5);
}											// Geser polygon 2D/3D ke kiri

void Polygon::moveRight() {
	clearPolygon();
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setX(kumpulanPointAlas[i].getX()+5);
	}
	centrePolygon.setX(centrePolygon.getX()+5);
}

int Polygon::jumlahTitikPolygon() {
	return kumpulanPointAlas.size();
}

void Polygon::setCentrePolygon(Point centrePolygon) {
	this->centrePolygon.setX(centrePolygon.getX());
	this->centrePolygon.setY(centrePolygon.getY());
}

Point Polygon::getCentrePolygon() {
	return centrePolygon;
}
