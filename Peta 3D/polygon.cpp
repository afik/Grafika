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

void Polygon::drawPolygon() {

}										// Gambar alas polygon 2D

void Polygon::drawPolygon3D(int height) {

}

void Polygon::addPoint(list<Point> listPoint) {
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