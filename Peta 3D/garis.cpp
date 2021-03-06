#include "garis.h"

Garis::Garis()
{
	P1.setX(0);
	P1.setY(0);
	P2.setX(0);
	P2.setY(0);
}

Garis::Garis(Point P1, Point P2)
{
	this->P1 = P1;
	this->P2 = P2;
}

Garis::Garis(int x1, int y1, int x2, int y2) {
	P1.setX(x1);
	P1.setY(y1);
	P2.setX(x2);
	P2.setY(y2);
}

Garis::Garis(const Garis& g)
{
	this->P1 = g.P1;
	this->P2 = g.P2;
}

Garis& Garis::operator=(const Garis& g)
{
	this->P1 = g.P1;
	this->P2 = g.P2;
	return *this;
}

Garis::~Garis(){ }

void Garis::setPointP1(Point P1)
{
	this->P1 = P1;
}

void Garis::setPointP2(Point P2)
{
	this->P2 = P2;
}

Point Garis::getPointP1()
{
	return P1;
}

Point Garis::getPointP2()
{
	return P2;
}

void Garis::drawLine(Buffer b, Warna warna, int** matriks)
{
	// Figure out where in memory to put the pixel
	int dx =  abs(P2.getX()-P1.getX()), sx = P1.getX()<P2.getX() ? 1 : -1;
   	int dy = -abs(P2.getY()-P1.getY()), sy = P1.getY()<P2.getY() ? 1 : -1;
   	int err = dx+dy, e2;
   	int t1, t2;
   	Pixel p;
   	Point tempP1 = P1;
   	Point tempP2 = P2;
   	
	for (;;){
		// std::cout << "(" << tempP1.getX() << ", " << tempP1.getY() << ") ";
		if(matriks[tempP1.getY()][tempP1.getX()] == 0){
			// std::cout << "(" << tempP1.getX() << ", " << tempP1.getY() << ") ";
			p.putPixel(warna,tempP1.getX(), tempP1.getY(),b);			// output ke screen berdasarkan location			  
			matriks[tempP1.getY()][tempP1.getX()] = 1; 
		}
		e2 = 2*err;                                   
		if (e2 >= dy) {                                         /* e_xy+e_x > 0 */
			if (tempP1.getX() == tempP2.getX()) break;                       
			err += dy;
			tempP1.setX(tempP1.getX() + sx);
		}                                             
		if (e2 <= dx) {                                         /* e_xy+e_y < 0 */
			if (tempP1.getY() == tempP2.getY()) break;
			err += dx;
			tempP1.setY(tempP1.getY() + sy);
		}
	}
}
