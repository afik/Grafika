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
}										

void Polygon::drawPolygon3D(Buffer buff, int height, Warna w) {
	// Sorting titik-titik pembentuk alas polygon setelah diproyeksikan terlebih dahulu (asumsi point identik absis maupun ordinat)
	Point* hasilSortingPointSurface = sortKumpulanPointHorizontal();				
	// Cari batas point teratas di mana point masih visible (setelah diurutkan terlebih dahulu)					
	int batasOrdinatVisible = getCriticalOrdinatPoint(hasilSortingPointSurface[0], 
	        hasilSortingPointSurface[kumpulanPointAlas.size()-1]);
	// Proses menggambar garis yang visible terhadap pengguna
	int indexAwal = 0;
	int indexAwalHidden = 0;
	int indexAbsis = 1;
	while (indexAbsis < kumpulanPointAlas.size()) {
		if (hasilSortingPointSurface[indexAbsis].getY() >= batasOrdinatVisible) {	
			// cout << "Index Awal : " << indexAwal << endl;
			// cout << "Index Absis : " << indexAbsis << endl;					
			Point alasAtasIndexAwal(hasilSortingPointSurface[indexAwal].getX(), 
			        hasilSortingPointSurface[indexAwal].getY() - height);
			Point alasAtasIndexAkhir(hasilSortingPointSurface[indexAbsis].getX(),
			        hasilSortingPointSurface[indexAbsis].getY() - height);
			       
			Garis sisiAlas(hasilSortingPointSurface[indexAwal], hasilSortingPointSurface[indexAbsis]); 		// Garis tepi alas bawah polygon 3D
			sisiAlas.drawLine(buff, w); 
			Garis sisiTegakAwal(hasilSortingPointSurface[indexAwal], alasAtasIndexAwal);					// Garis tegak polygon 3D pertama
			sisiTegakAwal.drawLine(buff, w);
			Garis sisiTegakAbsis(hasilSortingPointSurface[indexAbsis], alasAtasIndexAkhir);					// Garis tegak polygon 3D kedua
			sisiTegakAbsis.drawLine(buff, w);
			Garis sisiAlasAtas1(alasAtasIndexAwal, alasAtasIndexAkhir);										// Garis tepi alas atas polygon 3D
			sisiAlasAtas1.drawLine(buff, w);
			
			indexAwal = indexAbsis;
		}
		else {			
			cout << "Index Hidden : " << indexAwalHidden << endl;
			cout << "Index Absis : " << indexAbsis << endl;	
			
			Point alasAtasIndexAwalHidden(hasilSortingPointSurface[indexAwalHidden].getX(), 
			        hasilSortingPointSurface[indexAwalHidden].getY() - height);
			Point alasAtasIndexAkhirHidden(hasilSortingPointSurface[indexAbsis].getX(),
			        hasilSortingPointSurface[indexAbsis].getY() - height);
			Garis sisiAlasAtas2(alasAtasIndexAwalHidden, alasAtasIndexAkhirHidden);
			sisiAlasAtas2.drawLine(buff, w);
																				
			indexAwalHidden = indexAbsis;
		}
		indexAbsis++;
	}
	Point alasAtasIndexAwalHidden(hasilSortingPointSurface[indexAwalHidden].getX(), 
			        hasilSortingPointSurface[indexAwalHidden].getY() - height);
	Point alasAtasIndexAkhir(hasilSortingPointSurface[kumpulanPointAlas.size()-1].getX(),
			        hasilSortingPointSurface[kumpulanPointAlas.size()-1].getY() - height);
	Garis sisiSisa(alasAtasIndexAwalHidden, alasAtasIndexAkhir);
	sisiSisa.drawLine(buff, w);
}

int Polygon::getCriticalOrdinatPoint(Point terujungKiri, Point terujungKanan) {
	if (terujungKiri.getY() < terujungKanan.getY()) {
			return terujungKiri.getY();
	}
	else {
			return terujungKanan.getY();
	}
}

Point* Polygon::sortKumpulanPointHorizontal() {
	static Point* sortingPointSurface = new Point[kumpulanPointAlas.size()];
	for (int i=0; i<kumpulanPointAlas.size(); i++) {				// Copy array attribute ke array lokal
		sortingPointSurface[i].setX(kumpulanPointAlas[i].getX());
		sortingPointSurface[i].setY(kumpulanPointAlas[i].getY());
	}
	
	bool unSorted = true;										// Sorting point pembentuk alas secara absis dengan bubble sort
	while (unSorted) {
		unSorted = false;
		for (int i=0;i<(kumpulanPointAlas.size()-1);i++) {
			if (sortingPointSurface[i].getX() > sortingPointSurface[i+1].getX()) {
				unSorted = true;									// Jika revertible true maka proses swapping 
																		// untuk iterasi berikutnya dihentikan
				int absisPointSwap, ordinatPointSwap;
				absisPointSwap = sortingPointSurface[i].getX();			// Proses swapping dimulai di sini
				ordinatPointSwap = sortingPointSurface[i].getY();
				sortingPointSurface[i].setX(sortingPointSurface[i+1].getX());
				sortingPointSurface[i].setY(sortingPointSurface[i+1].getY());
				sortingPointSurface[i+1].setX(absisPointSwap);
				sortingPointSurface[i+1].setY(ordinatPointSwap);
			}
		}
	}
	return sortingPointSurface;
}

void Polygon::addPoint(vector<Point> listPoint) {
	kumpulanPointAlas = listPoint;
}

void Polygon::clearPolygon(int height) {
	Buffer buff;
	drawPolygon3D(buff, height, *Warna::hitam());
}										// Hapus polygon 

void Polygon::fillPolygonColor() {

}								// Isi polygon dengan warna tertentu

void Polygon::fillPolygonPattern() {

}									// Isi polygon dengan pattern tertentu

void Polygon::moveUp(int height) {
	clearPolygon(height);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setY(kumpulanPointAlas[i].getY()-5);
	}
	centrePolygon.setY(centrePolygon.getY()-5);
}											// Geser polygon 2D/3D ke atas

void Polygon::moveDown(int height) {
	clearPolygon(height);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setY(kumpulanPointAlas[i].getY()+5);
	}
	centrePolygon.setY(centrePolygon.getY()+5);
}											// Geser polygon 2D/3D ke bawah

void Polygon::moveLeft(int height) {
	clearPolygon(height);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setX(kumpulanPointAlas[i].getX()-5);
	}
	centrePolygon.setX(centrePolygon.getX()-5);
}											// Geser polygon 2D/3D ke kiri

void Polygon::moveRight(int height) {
	clearPolygon(height);
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
