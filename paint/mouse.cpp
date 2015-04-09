#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"
#include "buffer.h"
#include "warna.h"
#include "garis.h"
#include "pointer.h"
#include "polygon.h"
<<<<<<< HEAD
#include "bentuk.h"
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

int kbhit(void)
{
  struct termios oldt, newt;
  int ch;
  int oldf;
 
  tcgetattr(STDIN_FILENO, &oldt);
  newt = oldt;
  newt.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &newt);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}
=======
#include "persegi.h"
#include "lingkaran.h"
>>>>>>> df7575d45c102682b1776ddf57a04f3f5ac1787a

main(){
        FILE *fmouse;
        char b[3];
        char input;
        fmouse = fopen("/dev/input/mice","r");
        int xd=0,yd=0; //x/y movement delta
        int xo=0,yo=0; //x/y overflow (out of range -255 to +255)
        int lb=0,mb=0,rb=0,hs=0,vs=0; //left/middle/right mousebutton
        int run=0;
        int lb0 = 0;

        int panjang =0;
        int lebar=0;

        Buffer buff;
        Pixel p;
        Warna putih;
        Warna hitam(0,0,0);
        Pointer kursor;
        Polygon polygon;
        Persegi persegi;
        Lingkaran lingkaran;
        Point P1;
        Point P0;

<<<<<<< HEAD
        vector<Bentuk> list_bentuk;
        vector<Polygon> list_polygon;
=======
        int x = 300;
        int y = 300;
>>>>>>> df7575d45c102682b1776ddf57a04f3f5ac1787a

        Point titikTengah(x,y);
        lingkaran.setCenter(titikTengah);

        kursor.setPosisi(x,y);
        while(!run){
                fread(b,sizeof(char),3,fmouse);
                lb=(b[0]&1)>0;
                rb=(b[0]&2)>0;
                mb=(b[0]&4)>0;
                hs=(b[0]&16)>0;
                vs=(b[0]&32)>0;
                xo=(b[0]&64)>0;
                yo=(b[0]&128)>0;
                xd=b[1];
                yd=b[2];
                //printf("hs=%d,vs=%d,lb=%d rm=%d mb=%d xo=%d yo=%d xd=%d yd=%d\n",hs,vs,lb,rb,mb,xo,yo,xd,yd);
                
                /** tambahan setiap gerak */
                if(x > 10 && x < 1300){
                    x = x + xd;                        
                }

                /** batas kiri kanan */
                if(x <= 10){
                    x = 11;
                }
                if(x >= 1300){
                    x = 1299;
                }

                /** tambahan setiap gerak */
                if(y > 10 && y < 700){
                    y = y - yd;                        
                }

                /** batas atas bawah*/
                if(y <= 10){
                    y = 11;
                }
                if(y >= 700){
                    y = 699;
                }

                kursor.clearPointer(buff);
                kursor.setPosisi(x+1,y+1);
                kursor.drawPointer(buff);

                //printf("%d, %d\n", x, y);
            
                if((lb0==0) && (lb==1)){
                       //kursor.putPixel(warna, buff);

                    if(!polygon.isStop()){
                        Point p(x-1,y-1);
                        polygon.addPoint(p);

                    }
                    else {
                        list_polygon.push_back(polygon);
                    }

                    //P1 = Point(x,y);
                }
                else if((lb0==1) && (lb==1)){

                    // bentuk.persegi(P0, panjang, lebar, buff, hitam);
                    // P0 = Point(min(x,P1.getX()), min(y,P1.getY()));

                    // panjang = abs(x-P1.getX());
                    // lebar = abs(y-P1.getY());
                    
                    // bentuk.persegi(P0, panjang, lebar, buff, putih);

                    /** PERSEGI */
                    // persegi.clearPersegi(buff);
                    // P0 = Point(min(x,P1.getX()), min(y,P1.getY()));

                    // persegi.setPanjang(abs(x-P1.getX()));
                    // persegi.setLebar(abs(y-P1.getY()));
                    // persegi.setKiriAtas(P0);

                    // persegi.drawPersegi(putih, buff);

                    /** LINGKARAN */
                    // lingkaran.clearLingkaran(buff);
                    
                    // P0 = Point(min(x,P1.getX()), min(y,P1.getY()));

                    // lingkaran.setRadius(abs(x-P1.getX()));
                    // lingkaran.setCenter(P0);

                    // lingkaran.drawLingkaran(putih, buff);
                }
                else if((lb0==1) && (lb==0)){
                    //list_bentuk.push_back(bentuk);
                }

                polygon.drawPolygon();
                lb0 = lb;
                

                // polygon.drawPolygon();

        lb0 = lb;

    }
    fclose(fmouse);
    buff.closeBuffer();
}
