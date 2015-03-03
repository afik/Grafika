#include "baling.h"

Baling::Baling(){
	hitam.setRed(1);
	hitam.setGreen(1);
	hitam.setBlue(1);
	putih.setRed(255);
	putih.setGreen(255);
	putih.setBlue(255);
	center.setX(200);
	center.setY(200);
	radius = 3;
}
Baling::~Baling(){}

void Baling::setRadius(int radius)
{
	this->radius = radius;
}

int Baling::getRadius()
{
	return radius;
}

void Baling::circle(int Radius, Buffer buf, Warna w){
	Pixel p;
	int iCntr, x, y,p0;
    x=0;
    y=Radius;
    int xCenter=center.getX();
    int yCenter=center.getY();

    p0=(5/4)-Radius;

    p.putPixel(w,xCenter+x,yCenter+y,buf);
    p.putPixel(w,xCenter-x,yCenter+y,buf);
    p.putPixel(w,xCenter+x,yCenter-y,buf);
    p.putPixel(w,xCenter-x,yCenter-y,buf);
    p.putPixel(w,xCenter+y,yCenter+x,buf);
    p.putPixel(w,xCenter-y,yCenter+x,buf);
    p.putPixel(w,xCenter+y,yCenter-x,buf);
    p.putPixel(w,xCenter-y,yCenter-x,buf);


    while(x<=y)
    {
        if(p0 < 0)
        {
            p0=p0 + 2*(x+1) + 1;
            x=x+1;
        }
        else
        {
            p0=p0 + 2*(x+1) + 1 - 2*(y-1);
            x=x+1;
            y=y-1;
        }
	    p.putPixel(w,xCenter+x,yCenter+y,buf);
	    p.putPixel(w,xCenter-x,yCenter+y,buf);
	    p.putPixel(w,xCenter+x,yCenter-y,buf);
	    p.putPixel(w,xCenter-x,yCenter-y,buf);
	    p.putPixel(w,xCenter+y,yCenter+x,buf);
	    p.putPixel(w,xCenter-y,yCenter+x,buf);
	    p.putPixel(w,xCenter+y,yCenter-x,buf);
	    p.putPixel(w,xCenter-y,yCenter-x,buf);
    }
}
void Baling::baling(Buffer buf) {
	circle(radius, buf, putih); 

	//kuadran 1
	Point atas1(center.getX()+30,center.getY()-40);
	Point bawah1(center.getX()+50,center.getY()-15);
	Point jbawah1(center.getX()+radius,center.getY());
	Point jatas1(center.getX(),center.getY()-radius);
	Garis g11(atas1,bawah1); g11.drawLine(buf,putih);
	Garis g21(atas1,jatas1); g21.drawLine(buf,putih);
	Garis g31(bawah1,jbawah1); g31.drawLine(buf,putih);

	//kuadran 2
	Point atas2(center.getX()-30,center.getY()-40);
	Point bawah2(center.getX()-50,center.getY()-15);
	Point jbawah2(center.getX()-radius,center.getY());
	Point jatas2(center.getX(),center.getY()-radius);
	Garis g12(atas2,bawah2); g12.drawLine(buf,putih);
	Garis g22(atas2,jatas2); g22.drawLine(buf,putih);
	Garis g32(bawah2,jbawah2); g32.drawLine(buf,putih);

	//kuadran 3
	Point atas3(center.getX()-30,center.getY()+40);
	Point bawah3(center.getX()-50,center.getY()+15);
	Point jbawah3(center.getX()-radius,center.getY());
	Point jatas3(center.getX(),center.getY()+radius);
	Garis g13(atas3,bawah3); g13.drawLine(buf,putih);
	Garis g23(atas3,jatas3); g23.drawLine(buf,putih);
	Garis g33(bawah3,jbawah3); g33.drawLine(buf,putih);

	//kuadran 4
	Point atas4(center.getX()+30,center.getY()+40);
	Point bawah4(center.getX()+50,center.getY()+15);
	Point jbawah4(center.getX()+radius,center.getY());
	Point jatas4(center.getX(),center.getY()+radius);
	Garis g14(atas4,bawah4); g14.drawLine(buf,putih);
	Garis g24(atas4,jatas4); g24.drawLine(buf,putih);
	Garis g34(bawah4,jbawah4); g34.drawLine(buf,putih);

}
void Baling::rotasiBaling(int sudut, Buffer buf){
	circle(radius, buf, putih); 
	Point atas1(center.getX()+30,center.getY()-40);
	Point bawah1(center.getX()+50,center.getY()-15);
	Point jbawah1(center.getX()+radius,center.getY());
	Point jatas1(center.getX(),center.getY()-radius);
	Garis g11(rotasiTitik(atas1,sudut),rotasiTitik(bawah1,sudut)); g11.drawLine(buf,putih);
	Garis g21(rotasiTitik(atas1,sudut),rotasiTitik(jatas1,sudut)); g21.drawLine(buf,putih);
	Garis g31(rotasiTitik(bawah1,sudut),rotasiTitik(jbawah1,sudut)); g31.drawLine(buf,putih);

	//kuadran 2
	Point atas2(center.getX()-30,center.getY()-40);
	Point bawah2(center.getX()-50,center.getY()-15);
	Point jbawah2(center.getX()-radius,center.getY());
	Point jatas2(center.getX(),center.getY()-radius);
	Garis g12(rotasiTitik(atas2,sudut),rotasiTitik(bawah2,sudut)); g12.drawLine(buf,putih);
	Garis g22(rotasiTitik(atas2,sudut),rotasiTitik(jatas2,sudut)); g22.drawLine(buf,putih);
	Garis g32(rotasiTitik(bawah2,sudut),rotasiTitik(jbawah2,sudut)); g32.drawLine(buf,putih);

	//kuadran 3
	Point atas3(center.getX()-30,center.getY()+40);
	Point bawah3(center.getX()-50,center.getY()+15);
	Point jbawah3(center.getX()-radius,center.getY());
	Point jatas3(center.getX(),center.getY()+radius);
	Garis g13(rotasiTitik(atas3,sudut),rotasiTitik(bawah3,sudut)); g13.drawLine(buf,putih);
	Garis g23(rotasiTitik(atas3,sudut),rotasiTitik(jatas3,sudut)); g23.drawLine(buf,putih);
	Garis g33(rotasiTitik(bawah3,sudut),rotasiTitik(jbawah3,sudut)); g33.drawLine(buf,putih);

	//kuadran 4
	Point atas4(center.getX()+30,center.getY()+40);
	Point bawah4(center.getX()+50,center.getY()+15);
	Point jbawah4(center.getX()+radius,center.getY());
	Point jatas4(center.getX(),center.getY()+radius);
	Garis g14(rotasiTitik(atas4,sudut),rotasiTitik(bawah4,sudut)); g14.drawLine(buf,putih);
	Garis g24(rotasiTitik(atas4,sudut),rotasiTitik(jatas4,sudut)); g24.drawLine(buf,putih);
	Garis g34(rotasiTitik(bawah4,sudut),rotasiTitik(jbawah4,sudut)); g34.drawLine(buf,putih);
}
Point Baling::getCenter(){
	return center;
}
void Baling::setCenter(Point _center){
	center.setX(_center.getX());
	center.setY(_center.getY());
}
void Baling::clearBaling(int sudut, Buffer buf){
	circle(radius, buf, hitam); 
	Point atas1(center.getX()+30,center.getY()-40);
	Point bawah1(center.getX()+50,center.getY()-15);
	Point jbawah1(center.getX()+radius,center.getY());
	Point jatas1(center.getX(),center.getY()-radius);
	Garis g11(rotasiTitik(atas1,sudut),rotasiTitik(bawah1,sudut)); g11.drawLine(buf,hitam);
	Garis g21(rotasiTitik(atas1,sudut),rotasiTitik(jatas1,sudut)); g21.drawLine(buf,hitam);
	Garis g31(rotasiTitik(bawah1,sudut),rotasiTitik(jbawah1,sudut)); g31.drawLine(buf,hitam);

	//kuadran 2
	Point atas2(center.getX()-30,center.getY()-40);
	Point bawah2(center.getX()-50,center.getY()-15);
	Point jbawah2(center.getX()-radius,center.getY());
	Point jatas2(center.getX(),center.getY()-radius);
	Garis g12(rotasiTitik(atas2,sudut),rotasiTitik(bawah2,sudut)); g12.drawLine(buf,hitam);
	Garis g22(rotasiTitik(atas2,sudut),rotasiTitik(jatas2,sudut)); g22.drawLine(buf,hitam);
	Garis g32(rotasiTitik(bawah2,sudut),rotasiTitik(jbawah2,sudut)); g32.drawLine(buf,hitam);

	//kuadran 3
	Point atas3(center.getX()-30,center.getY()+40);
	Point bawah3(center.getX()-50,center.getY()+15);
	Point jbawah3(center.getX()-radius,center.getY());
	Point jatas3(center.getX(),center.getY()+radius);
	Garis g13(rotasiTitik(atas3,sudut),rotasiTitik(bawah3,sudut)); g13.drawLine(buf,hitam);
	Garis g23(rotasiTitik(atas3,sudut),rotasiTitik(jatas3,sudut)); g23.drawLine(buf,hitam);
	Garis g33(rotasiTitik(bawah3,sudut),rotasiTitik(jbawah3,sudut)); g33.drawLine(buf,hitam);

	//kuadran 4
	Point atas4(center.getX()+30,center.getY()+40);
	Point bawah4(center.getX()+50,center.getY()+15);
	Point jbawah4(center.getX()+radius,center.getY());
	Point jatas4(center.getX(),center.getY()+radius);
	Garis g14(rotasiTitik(atas4,sudut),rotasiTitik(bawah4,sudut)); g14.drawLine(buf,hitam);
	Garis g24(rotasiTitik(atas4,sudut),rotasiTitik(jatas4,sudut)); g24.drawLine(buf,hitam);
	Garis g34(rotasiTitik(bawah4,sudut),rotasiTitik(jbawah4,sudut)); g34.drawLine(buf,hitam);
}
Point Baling::rotasiTitik(Point p, int sudut){
	Point rot;
	float sudutrad = (float) sudut * 2 * PI / 360;
	float xaksen = (p.getX() - center.getX()) * cos(sudutrad) - (p.getY() - center.getY()) * sin(sudutrad) + center.getX();
	float yaksen = (p.getX() - center.getX()) * sin(sudutrad) + (p.getY() - center.getY()) * cos(sudutrad) + center.getY();
	Point point(convertToInt(xaksen), convertToInt(yaksen));
	return point;
}
int Baling::convertToInt(float f){
	int temp;
	if(f >= 0){
		temp = (int) (f + 0.5); 
	}
	else {
		temp = (int) (f - 0.5); 
	}
	return temp;
}
