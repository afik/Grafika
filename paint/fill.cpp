#include "fill.h"

using namespace std;

void Fill::FloodFill(Point posisi, Warna warnaLama, Warna warna, Buffer buf)
{
	Pixel p;
	Warna now = p.getPixel(posisi,buf);
	stackfill.push(posisi);
	while(!stackfill.empty()){
		posisi.setX(stackfill.top().getX());
		posisi.setY(stackfill.top().getY());
        now = p.getPixel(posisi,buf);
        p.putPixel(warna,posisi,buf);
        stackfill.pop();
        // printf("%d %d %d\n",now.getRed(), now.getGreen(),now.getBlue()  );
        // printf("%d %d %d\n",warnaLama.getRed(), warnaLama.getGreen(),warnaLama.getBlue()  );
		if(now.getRed()==warnaLama.getRed() && now.getGreen()==warnaLama.getGreen() && now.getBlue()==warnaLama.getBlue()) {
	   		Point po(posisi.getX()-1,posisi.getY());
	    	stackfill.push(po);
	   		Point po2(posisi.getX()+1,posisi.getY());
			stackfill.push(po2);
	   		Point po3(posisi.getX(),posisi.getY()+1);
			stackfill.push(po3);
	   		Point po4(posisi.getX(),posisi.getY()-1);
			stackfill.push(po4);
	    }
	}
}

void Fill::FloodFill(int pointx, int pointy, Warna warnaLama, Warna warna, Buffer buf)
{
	Pixel p;
	Warna now = p.getPixel(pointx,pointy,buf);
	Point posisi(pointx,pointy);
	stackfill.push(posisi);
	while(!stackfill.empty()){
		posisi.setX(stackfill.top().getX());
		posisi.setY(stackfill.top().getY());
		now = p.getPixel(posisi,buf);
        p.putPixel(warna,posisi,buf); 
        stackfill.pop();
        // printf("%d %d %d\n",now.getRed(), now.getGreen(),now.getBlue()  );
        // printf("%d %d %d\n",warnaLama.getRed(), warnaLama.getGreen(),warnaLama.getBlue()  );
		if(now.getRed()==warnaLama.getRed() && now.getGreen()==warnaLama.getGreen() && now.getBlue()==warnaLama.getBlue()) {
	   		Point po(posisi.getX()-1,posisi.getY());
	    	stackfill.push(po);
	   		Point po2(posisi.getX()+1,posisi.getY());
			stackfill.push(po2);
	   		Point po3(posisi.getX(),posisi.getY()+1);
			stackfill.push(po3);
	   		Point po4(posisi.getX(),posisi.getY()-1);
			stackfill.push(po4);
	    }
	}
}