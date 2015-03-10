#include "point.h"
#include "garis.h"

Class polygon () {
	// Atribut kelas
	list<Point> kumpulanPointAlas;
	
	// Method Utama
	polygon(list<Point> kumpulanPoint); 						// assign point 2D alas
	void drawPolygon();											// Gambar alas polygon 2D
	void drawPolygon3D(int height);								// Gambar polygon 3D dari alas polygon
	void addPoint(point tambahanPoint);							// Tambah point pada polygon (asumsi masih 2D)
	Point getAlasCentre();										// Ambil pusat dari alas 2D
	void clearPolygon();										// Hapus polygon 
	void fillPolygonColor();									// Isi polygon dengan warna tertentu
	void fillPolygonPattern();									// Isi polygon dengan pattern tertentu
	void moveUp();												// Geser polygon 2D/3D ke atas
	void moveDown();											// Geser polygon 2D/3D ke bawah
	void moveLeft();											// Geser polygon 2D/3D ke kiri
	void moveRight();											// Geser polygon 2D/3D ke kanan
	//void doAntiClipping;										// Membantu proses clipping garis yang invisible
	
	// Setter dan getter
	
}
