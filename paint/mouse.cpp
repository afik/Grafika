#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"
#include "buffer.h"
#include "warna.h"
#include "garis.h"
#include "pointer.h"
#include "polygon.h"
#include "bentuk.h"

main(){
    FILE *fmouse;
    char b[3];
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
    Bentuk bentuk;
    Point P1;
    Point P0;

    vector<Bentuk> list_bentuk;

    static int batasKanan = 1200;
    static int batasBawah = 800;
    static int batasKiri = 10;
    static int batasAtas = 10;

    int x = 100;
    int y = 100;

    kursor.setPosisi(x,y);
    while(!run){
        /*********** Get Mouse Properties ***********/
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

        /*********** Get Mouse Movement ***********/
        if(x > 10 && x < 1000){
            x = x + xd;                        
        }
        if(x <= batasKiri){
            x = 11;
        }
        if(x >= batasKanan){
            x = 999;
        }
        if(y > 10 && y < 500){
            y = y - yd;                        
        }
        if(y <= batasAtas){
            y = 11;
        }
        if(y >= batasBawah){
            y = 499;
        }

        /************ Draw Kursor ***************/
        kursor.clearPointer(buff);
        kursor.setPosisi(x+1,y+1);
        kursor.drawPointer(buff);

        /********* Mouse Event ************/    
        if((lb0==0) && (lb==1)){
            P1 = Point(x,y);
        }
        else if((lb0==1) && (lb==1)){
            bentuk.persegi(P0, panjang, lebar, buff, hitam);
            P0 = Point(min(x,P1.getX()), min(y,P1.getY()));

            panjang = abs(x-P1.getX());
            lebar = abs(y-P1.getY());
            
            bentuk.persegi(P0, panjang, lebar, buff, putih);
        }
        else if((lb0==1) && (lb==0)){
        }

        lb0 = lb;

    }
    fclose(fmouse);
    buff.closeBuffer();
}
