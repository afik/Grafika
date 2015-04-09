polygon: mainPolygon.o polygon.o buffer.o garis.o pixel.o point.o warna.o 
	g++ -o polygon mainPolygon.o polygon.o buffer.o garis.o pixel.o point.o warna.o 

polygon.o: polygon.cpp
	g++ -c polygon.cpp	

buffer.o: buffer.cpp
	g++ -c buffer.cpp
	
garis.o: garis.cpp
	g++ -c garis.cpp
	
pixel.o: pixel.cpp
	g++ -c pixel.cpp

point.o: point.cpp
	g++ -c point.cpp

warna.o: warna.cpp 
	g++ -c warna.cpp
	
clean:
	rm *o polygon