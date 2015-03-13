#ifndef _POLYGON_H
#define _POLYGON_H

#include "point.h"
#include "garis.h"
#include "warna.h"
#include "buffer.h"
#include "pixel.h"
#include <vector>

class Polygon {
	// Atribut kelas
private:
	vector<Point> kumpulanPointAlas;
	Point centrePolygon;

	// Method Utama
public:	
	Polygon();
	Polygon(Point centrePolygon); 								// assign point 2D alas
	Polygon(const Polygon& poly);
	Polygon& operator=(const Polygon& poly);
	~Polygon();
	
	void drawPolygon(Buffer buff, Warna w);											// Gambar alas polygon 2D
	void drawPolygon3D(Buffer buff, int height, Warna w);							// Gambar polygon 3D dari alas polygon
	Point* sortKumpulanPointHorizontal();											// Urutkan secara membesar point pembentuk alas berdasarkan sumbu X
	int getCriticalOrdinatPoint(Point terujungKiri, Point terujungKanan);			// Fungsi untuk mendapatkan ordinat minimal dari kedua ujung point kiri dan kanan
	void addPoint(vector<Point> listPoint);						// Tambah point-point ujung alas polygon  
	void clearPolygon();										// Hapus polygon 
	void fillPolygonColor();									// Isi polygon dengan warna tertentu
	void fillPolygonPattern();									// Isi polygon dengan pattern tertentu
	void moveUp();												// Geser polygon 2D/3D ke atas
	void moveDown();											// Geser polygon 2D/3D ke bawah
	void moveLeft();											// Geser polygon 2D/3D ke kiri
	void moveRight();											// Geser polygon 2D/3D ke kanan
	//void doAntiClipping;										// Membantu proses clipping garis yang invisible
	
	// Setter dan getter
	int jumlahTitikPolygon();									// Hitung jumlah titik pembentuk polygon
	Point getCentrePolygon();									// Ambil pusat dari alas 2D								 
	void setCentrePolygon(Point centre);
};

#endif
