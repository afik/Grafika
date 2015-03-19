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

void Polygon::drawPolygon(Buffer buff, Warna w, int** matriks) {

	for(int i=0; i<jumlahTitikPolygon(); i++)
	{
		if(i<jumlahTitikPolygon()-1)
		{
			Garis g(kumpulanPointAlas[i].getX(), kumpulanPointAlas[i].getY(),
					kumpulanPointAlas[i+1].getX(), kumpulanPointAlas[i+1].getY());
			g.drawLine(buff, w, matriks);
		}
		else
		{
			Garis g(kumpulanPointAlas[i].getX(), kumpulanPointAlas[i].getY(),
					kumpulanPointAlas[0].getX(), kumpulanPointAlas[0].getY());
			g.drawLine(buff, w, matriks);
		}
	}
}										

void Polygon::drawPolygon3D(Buffer buff, int height, Warna w, int** matriks) {
	// Sorting titik-titik pembentuk alas polygon setelah diproyeksikan terlebih dahulu (asumsi point identik absis maupun ordinat)
	Point* hasilSortingPointSurface = sortKumpulanPointHorizontal();				
	// Cari batas point teratas di mana point masih visible (setelah diurutkan terlebih dahulu)					
	int batasOrdinatVisible = getCriticalOrdinatPoint(hasilSortingPointSurface[0], 
	        hasilSortingPointSurface[kumpulanPointAlas.size()-1]);
	// Proses menggambar garis yang visible terhadap pengguna
	int indexAwal = 0;
	int indexAwalHidden = 0;
	int indexAbsis = 1;
	
	Point alasAtasIndexAwal(hasilSortingPointSurface[0].getX(), 
			        hasilSortingPointSurface[0].getY()-height);
	Garis sisiTegakPertama(hasilSortingPointSurface[0], alasAtasIndexAwal);
	sisiVisiblePolygon.push_back(sisiTegakPertama);
	
	while (indexAbsis < kumpulanPointAlas.size()) {
		if (hasilSortingPointSurface[indexAbsis].getY() >= batasOrdinatVisible) {	
			// cout << "Index Awal : " << indexAwal << endl;
			// cout << "Index Absis : " << indexAbsis << endl;					
			Point alasAtasIndexAwal(hasilSortingPointSurface[indexAwal].getX(), 
			        hasilSortingPointSurface[indexAwal].getY() - height);
			Point alasAtasIndexAkhir(hasilSortingPointSurface[indexAbsis].getX(),
			        hasilSortingPointSurface[indexAbsis].getY() - height);
			       
			Garis sisiAlas(hasilSortingPointSurface[indexAwal], hasilSortingPointSurface[indexAbsis]); 		// Garis tepi alas bawah polygon 3D
			sisiAlas.drawLine(buff, w, matriks); sisiVisiblePolygon.push_back(sisiAlas); setBidang(matriks);			
			Garis sisiTegakAwal(hasilSortingPointSurface[indexAwal], alasAtasIndexAwal);					// Garis tegak polygon 3D pertama
			sisiTegakAwal.drawLine(buff, w, matriks); 
			Garis sisiTegakAbsis(hasilSortingPointSurface[indexAbsis], alasAtasIndexAkhir);					// Garis tegak polygon 3D kedua
			sisiTegakAbsis.drawLine(buff, w, matriks); sisiVisiblePolygon.push_back(sisiTegakAbsis);setBidang(matriks);
			Garis sisiAlasAtas1(alasAtasIndexAwal, alasAtasIndexAkhir);										// Garis tepi alas atas polygon 3D
			sisiAlasAtas1.drawLine(buff, w, matriks); sisiVisiblePolygon.push_back(sisiAlasAtas1);setBidang(matriks);
			
			indexAwal = indexAbsis;
		}
		else {			
			// cout << "Index Hidden : " << indexAwalHidden << endl;
			// cout << "Index Absis : " << indexAbsis << endl;	
			
			Point alasAtasIndexAwalHidden(hasilSortingPointSurface[indexAwalHidden].getX(), 
			        hasilSortingPointSurface[indexAwalHidden].getY() - height); 
			Point alasAtasIndexAkhirHidden(hasilSortingPointSurface[indexAbsis].getX(),
			        hasilSortingPointSurface[indexAbsis].getY() - height);
			        
			Garis sisiAlasAtas2Hidden(alasAtasIndexAwalHidden, alasAtasIndexAkhirHidden);
			sisiAlasAtas2Hidden.drawLine(buff, w, matriks); sisiVisiblePolygon.push_back(sisiAlasAtas2Hidden);setBidang(matriks);
																				
			indexAwalHidden = indexAbsis;
		}
		indexAbsis++;
	}
	Point alasAtasIndexAwalHidden(hasilSortingPointSurface[indexAwalHidden].getX(), 
			        hasilSortingPointSurface[indexAwalHidden].getY() - height);
	Point alasAtasIndexAkhir(hasilSortingPointSurface[kumpulanPointAlas.size()-1].getX(),
			        hasilSortingPointSurface[kumpulanPointAlas.size()-1].getY() - height);
	Garis sisiSisa(alasAtasIndexAwalHidden, alasAtasIndexAkhir);
	sisiSisa.drawLine(buff, w, matriks); sisiVisiblePolygon.push_back(sisiSisa);setBidang(matriks);
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

void Polygon::clearPolygon(int height, int** matriks) {
	Buffer buff;
	drawPolygon3D(buff, height, *Warna::hitam(), matriks);
}										// Hapus polygon 

void Polygon::fillPolygonColor() {

}								// Isi polygon dengan warna tertentu

void Polygon::fillPolygonPattern() {

}									// Isi polygon dengan pattern tertentu

void Polygon::moveUp(int height, int** matriks) {
	clearPolygon(height, matriks);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setY(kumpulanPointAlas[i].getY()-5);
	}
	centrePolygon.setY(centrePolygon.getY()-5);
}											// Geser polygon 2D/3D ke atas

void Polygon::moveDown(int height, int** matriks) {
	clearPolygon(height, matriks);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setY(kumpulanPointAlas[i].getY()+5);
	}
	centrePolygon.setY(centrePolygon.getY()+5);
}											// Geser polygon 2D/3D ke bawah

void Polygon::moveLeft(int height, int** matriks) {
	clearPolygon(height, matriks);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setX(kumpulanPointAlas[i].getX()-5);
	}
	centrePolygon.setX(centrePolygon.getX()-5);
}											// Geser polygon 2D/3D ke kiri

void Polygon::moveRight(int height, int** matriks) {
	clearPolygon(height, matriks);
	for(int i=0; i<kumpulanPointAlas.size(); i++) {
		kumpulanPointAlas[i].setX(kumpulanPointAlas[i].getX()+5);
	}
	centrePolygon.setX(centrePolygon.getX()+5);
}

void Polygon::setBidang(int** matriks){
	int jumlahTitik = 0;
	for(int i = 0; i < 600; i++){
		for(int j = 0; j < 1000; j++){
			if(matriks[i][j]==1) jumlahTitik++;
		}
		if(jumlahTitik%2 == 0 && jumlahTitik != 0){
			int j = 0;
			bool stop = false;
			while(j < 1000 && !stop){
				if(matriks[i][j]==0) j++;
				else stop = true;
			}
			for(int k = 0; k < jumlahTitik/2; k++){
				j++; stop = false;
				while(j < 600 && !stop){
					if(matriks[i][j]==1) stop = true;
					else matriks[i][j] = 1;
				}
				j++; stop = false;
				while(j < 1000 && !stop){
					if(matriks[i][j]==0) j++;
					else stop = true;
				}
			}
		}
		if(jumlahTitik%2 == 1 && jumlahTitik != 1){
			int j = 0;
			bool stop = false;
			while(j < 1000 && !stop){
				if(matriks[i][j]==0) j++;
				else stop = true;
			}
			for(int k = 0; k < jumlahTitik/2; k++){
				j++; stop = false;
				while(j < 600 && !stop){
					if(matriks[i][j]==1) stop = true;
					else matriks[i][j] = 1;
				}
			}
		}
	}
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

Garis Polygon::getGarisVisiblePolygon(int indexGaris) {
	return sisiVisiblePolygon[indexGaris];
}

int Polygon::banyakGarisVisiblePolygon() {
	return sisiVisiblePolygon.size();
}
