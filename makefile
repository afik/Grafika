all: grapika

tesafik: maintesbola.o buffer.o kapal.o garis.o pixel.o point.o warna.o scanline.o
	g++ -o tesafik maintesbola.o buffer.o kapal.o garis.o pixel.o point.o warna.o scanline.o

grapika: main.o bentuk.o buffer.o kapal.o  badanHeli.o ekorHeli.o helikopter.o garis.o pixel.o point.o warna.o parasut.o scanline.o baling.o
	g++ -o grapika main.o bentuk.o buffer.o kapal.o  badanHeli.o ekorHeli.o helikopter.o garis.o pixel.o point.o warna.o parasut.o scanline.o baling.o

kopter : mainBaling.o buffer.o baling.o pixel.o point.o garis.o warna.o
	g++ -o kopter mainBaling.o buffer.o baling.o pixel.o point.o garis.o warna.o
	
maintes.o: maintesbola.cpp
	g++ -c maintesbola.cpp

mainBaling.o: mainBaling.cpp
	g++ -c mainBaling.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
buffer.o: buffer.cpp
	g++ -c buffer.cpp
	
baling.o: baling.cpp
	g++ -c baling.cpp

garis.o: garis.cpp
	g++ -c garis.cpp
	
kapal.o: kapal.cpp
	g++ -c kapal.cpp

badanHeli.o: badanHeli.cpp
	g++ -c badanHeli.cpp

ekorHeli.o: ekorHeli.cpp
	g++ -c ekorHeli.cpp

helikopter.o: helikopter.cpp
	g++ -c helikopter.cpp	

pixel.o: pixel.cpp
	g++ -c pixel.cpp

point.o: point.cpp
	g++ -c point.cpp

warna.o: warna.cpp 
	g++ -c warna.cpp
	
bentuk.o: bentuk.cpp 
	g++ -c bentuk.cpp

parasut.o: parasut.cpp 
	g++ -c parasut.cpp

scanline.o: scanline.cpp
	g++ -c scanline.cpp

clean:
	rm *o grapika
	
clean_kopter:
	rm *o kopter

ctesafik:
	rm *o tesafik
