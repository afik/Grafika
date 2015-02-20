all: grapika

grapika: main.o buffer.o kapal.o garis.o pixel.o point.o warna.o
	g++ -o grapika main.o buffer.o kapal.o garis.o pixel.o point.o warna.o

main.o: main.cpp
	g++ -c main.cpp
	
buffer.o: buffer.cpp
	g++ -c buffer.cpp

garis.o: garis.cpp
	g++ -c garis.cpp
	
kapal.o: kapal.cpp
	g++ -c kapal.cpp

pixel.o: pixel.cpp
	g++ -c pixel.cpp

point.o: point.cpp
	g++ -c point.cpp

warna.o: warna.cpp 
	g++ -c warna.cpp

clean:
	rm *o grapika
