#include <stdio.h>
#include <stdlib.h>
#include "pixel.h"
#include "buffer.h"
#include "warna.h"
#include "garis.h"
#include "pointer.h"
#include "polygon.h"
#include "bentuk.h"
#include "persegi.h"
#include "lingkaran.h"
#include "fill.h"

Buffer buff;
Pixel px;
void palette();
void tombol();
main(){
        FILE *fmouse;
        char b[3];
        fmouse = fopen("/dev/input/mice","r");
        int xd=0,yd=0; //x/y movement delta
        int xo=0,yo=0; //x/y overflow (out of range -255 to +255)
        int lb=0,mb=0,rb=0,hs=0,vs=0; //left/middle/right mousebutton
        int run=0;
        int lb0 = 0;

        bool kotak;
        bool poly;
        bool buled;
        bool pill;

        Warna putih;
        Warna hitam(0,0,0);
        Warna warna;

        Pointer kursor;
        Polygon polygon;
        Persegi persegi;
        Lingkaran lingkaran;
        Fill fill;

        Point P1;
        Point P0;

       // vector<Bentuk> list_bentuk;
        vector<Polygon> list_polygon;
        int x = 300;
        int y = 300;

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

            if(lb==1) {
                if((x > 50 && x < 71) && (y>525 && y<546)){
                    poly = true;
                    kotak = false;
                    buled = false;
                    pill = false;
                }
                if((x > 80 && x < 101) && (y>525 && y<546)){
                    kotak = true;
                    poly = false;
                    buled = false;
                    pill = false;
                }

                if((x > 110 && x < 131) && (y>525 && y<546)){
                    buled = true;
                    kotak = false;
                    poly = false;
                    pill = false;
                }

                if((x > 140 && x < 161) && (y>525 && y<546)){
                    pill = true;
                    buled = false;
                    kotak = false;
                    poly = false;
                }
            }

            //printf("%d, %d\n", x, y);
            if(kotak) {
                
                if((lb0==0) && (lb==1)){
                    if((x > 50 && x < 305) && (y>10 && y<521)){
                        persegi.setWarna(px.getPixel(x,y,buff));                     
                    }
                    if(x>310){
                        P1 = Point(x,y);
                    }
                }
                else if((lb0==1) && (lb==1)){

                    /** PERSEGI */
                    persegi.clearPersegi(buff);
                    P0 = Point(min(x,P1.getX()), min(y,P1.getY()));

                    persegi.setPanjang(abs(x-P1.getX()));
                    persegi.setLebar(abs(y-P1.getY()));
                    persegi.setKiriAtas(P0);

                }
            }
            if(buled){
                if((lb0==0) && (lb==1)){
                    if((x > 50 && x < 305) && (y>10 && y<521)){
                        lingkaran.setWarna(px.getPixel(x,y,buff));                     
                    }
                    if(x>310){
                        P1 = Point(x,y);
                    }
                }
                else if((lb0==1) && (lb==1)){

                    /** LINGKARAN */
                    lingkaran.clearLingkaran(buff);
                    
                    P0 = Point(min(x,P1.getX()), min(y,P1.getY()));

                    lingkaran.setRadius(abs(x-P1.getX()));
                    lingkaran.setCenter(P0);

                    
                }
            }
            if(poly){
                
                if((lb0==0) && (lb==1)){
                    if((x > 50 && x < 305) && (y>10 && y<521)){
                        polygon.setWarna(px.getPixel(x,y,buff));                     
                    }
                       //kursor.putPixel(warna, buff);
                    if(x>310){

                        if(!polygon.isStop()){
                            Point p(x-1,y-1);
                            polygon.addPoint(p);

                        }
                        else {
                            list_polygon.push_back(polygon);
                        }
                    }

                    //P1 = Point(x,y);
                }

            }
            if(pill){
                if((lb0==0) && (lb==1)){
                    if((x > 50 && x < 305) && (y>10 && y<521)){
                        warna = px.getPixel(x,y,buff);                     
                    }

                    if(x>310){
                        fill.FloodFill(x,y, hitam, warna, buff);
                    }
                }
            }
                
            // else if((lb0==1) && (lb==0)){
            //     //list_bentuk.push_back(bentuk);
            // }
            persegi.drawPersegi(buff);
            lingkaran.drawLingkaran(buff);

            polygon.drawPolygon();
            palette();
            tombol();
            lb0 = lb;
            

            // polygon.drawPolygon();

        lb0 = lb;

    }
    fclose(fmouse);
    buff.closeBuffer();
}
 
void palette() {
    int x, y, a, b;

    for ( y = 10; y < 265; y++ ) {
        for ( x = 50; x < 305; x++ ) {
            a = y-10;
            b = x-50;
            Warna w(a,b,0);
            px.putPixel(w,x,y,buff);
        }
    }

    for ( y = 266; y < 521; y++ ) {
        for ( x = 50; x < 305; x++ ) {
            a = y-266;
            b = x-50; 
            Warna w(a,0,b);
            px.putPixel(w,x,y,buff);
        }
    }
}

void tombol() {

    Bentuk bentuk1, bentuk2, bentuk3, bentuk4;
    Point p(50,525);
    Point p2(80,525);
    Point p3(110,525);
    Point p4(140,525);

    bentuk1.persegi(p,20,20,buff, *Warna::putih());
    bentuk2.persegi(p2,20,20,buff,*Warna::hijau());
    bentuk3.persegi(p3,20,20,buff,*Warna::kuning());
    bentuk4.persegi(p4,20,20,buff,*Warna::biru());
}