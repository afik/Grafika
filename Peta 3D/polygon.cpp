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

void Polygon::drawPolygon(Buffer buff) {
	Warna putih(5, 174, 179);

	for(int i=0; i<jumlahTitikPolygon(); i++)
	{
		if(i<jumlahTitikPolygon()-1)
		{
			Garis g(kumpulanPointAlas[i].getX(), kumpulanPointAlas[i].getY(),
					kumpulanPointAlas[i+1].getX(), kumpulanPointAlas[i+1].getY());
			g.drawLine(buff, putih);
		}
		else
		{
			Garis g(kumpulanPointAlas[i].getX(), kumpulanPointAlas[i].getY(),
					kumpulanPointAlas[0].getX(), kumpulanPointAlas[0].getY());
			g.drawLine(buff, putih);
		}
	}
}										// Gambar alas polygon 2D

void Polygon::drawPolygon3D(int height) {

}

void Polygon::addPoint(vector<Point> listPoint) {
	kumpulanPointAlas = listPoint;
}

void Polygon::clearPolygon() {

}										// Hapus polygon 

void Polygon::fillPolygonColor() {

}								// Isi polygon dengan warna tertentu

void Polygon::fillPolygonPattern() {

}									// Isi polygon dengan pattern tertentu

void Polygon::moveUp() {

}											// Geser polygon 2D/3D ke atas

void Polygon::moveDown() {

}											// Geser polygon 2D/3D ke bawah

void Polygon::moveLeft() {

}											// Geser polygon 2D/3D ke kiri

void Polygon::moveRight() {

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