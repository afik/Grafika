#include "fill.h"

void Fill::FloodFill(Point posisi, Warna warnaLama, Warna warna, Buffer buf)
{
	Pixel p;
	Warna now = p.getPixel(posisi,buf);
	if(now.getRed()!=warnaLama.getRed() && now.getGreen()!=warnaLama.getGreen() && 
		now.getBlue()!=warnaLama.getBlue()) {
        p.putPixel(warna,posisi,buf);
        FloodFill(posisi.getX()-1,posisi.getY(),warnaLama,warna,buf);
        FloodFill(posisi.getX()+1,posisi.getY(),warnaLama,warna,buf);
        FloodFill(posisi.getX(),posisi.getY()+1,warnaLama,warna,buf);
        FloodFill(posisi.getX(),posisi.getY()-1,warnaLama,warna,buf);
        
    }
}

void Fill::FloodFill(int pointx, int pointy, Warna warnaLama, Warna warna, Buffer buf)
{
	Pixel p;
	Warna now = p.getPixel(pointx,pointy,buf);

	if(now.getRed()!=warnaLama.getRed() && now.getGreen()!=warnaLama.getGreen() && 
		now.getBlue()!=warnaLama.getBlue()) {
		p.putPixel(warna,pointx,pointy,buf);
        FloodFill(pointx-1,pointy,warnaLama,warna,buf);
        FloodFill(pointx+1,pointy,warnaLama,warna,buf);
        FloodFill(pointx,pointy+1,warnaLama,warna,buf);
        FloodFill(pointx,pointy-1,warnaLama,warna,buf);
    }
}

void Fill::patternFill(Point start, Warna warnaLama, char flag, Buffer buf){
	Pixel p; Pattern pat;
	Warna now = p.getPixel(start,buf);
	if(now.getRed()!=warnaLama.getRed() && now.getGreen()!=warnaLama.getGreen() && 
		now.getBlue()!=warnaLama.getBlue()) {
        //cout << "pat" << endl;
        Warna warna; int i, j;
        if (flag=='i') {
			
			i = start.getX()%12;
			j = start.getY()%10;
			warna.setRed(pat.ikan[i][j].getRed());
			warna.setGreen(pat.ikan[i][j].getGreen());
			warna.setBlue(pat.ikan[i][j].getBlue());
			
		}
		else if (flag=='b') {
			i = start.getX()%7;
			j = start.getY()%5;
			warna.setRed(pat.burung[i][j].getRed());
			warna.setGreen(pat.burung[i][j].getGreen());
			warna.setBlue(pat.burung[i][j].getBlue());
		}
        p.putPixel(warna,start,buf);
        patternFill(start.getX(),start.getY()+1,warnaLama,flag,buf);
        patternFill(start.getX(),start.getY()-1,warnaLama,flag,buf);
        patternFill(start.getX()-1,start.getY(),warnaLama,flag,buf);
        patternFill(start.getX()+1,start.getY(),warnaLama,flag,buf);        
    }
}

void Fill::patternFill(int pointx, int pointy, Warna warnaLama, char flag, Buffer buf){
	Pixel p; Pattern pat;
	Warna now = p.getPixel(pointx,pointy,buf);
	if(now.getRed()!=warnaLama.getRed() && now.getGreen()!=warnaLama.getGreen() && 
		now.getBlue()!=warnaLama.getBlue()) {
        Warna warna; int i, j;
        if (flag=='i') {
			i = pointx%12;
			j = pointy%10;
			warna.setRed(pat.ikan[i][j].getRed());
			warna.setGreen(pat.ikan[i][j].getGreen());
			warna.setBlue(pat.ikan[i][j].getBlue());
			
		}
		else if (flag=='b') {
			i = pointx%7;
			j = pointy%5;
			warna.setRed(pat.burung[i][j].getRed());
			warna.setGreen(pat.burung[i][j].getGreen());
			warna.setBlue(pat.burung[i][j].getBlue());
		}
        p.putPixel(warna,pointx,pointy,buf);
        patternFill(pointx-1,pointy,warnaLama,flag,buf);
        patternFill(pointx+1,pointy,warnaLama,flag,buf);
        patternFill(pointx,pointy+1,warnaLama,flag,buf);
        patternFill(pointx,pointy-1,warnaLama,flag,buf);
    }
}
