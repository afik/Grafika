perspective: main_fill.o buffer.o warna.o point.o balok1tm.o fill_scan.o garis.o pixel.o
	g++ -o perspective main_fill.o buffer.o warna.o point.o balok1tm.o fill_scan.o garis.o pixel.o
	

main_fill.o: main_fill.cpp
	g++ -c main_fill.cpp

point.o: point.cpp
	g++ -c point.cpp

warna.o: warna.cpp 
	g++ -c warna.cpp
	
buffer.o: buffer.cpp
	g++ -c buffer.cpp

balok1tm.o: balok1tm.cpp
	g++ -c balok1tm.cpp

fill_scan.o: fill_scan.cpp
	g++ -c fill_scan.cpp

garis.o: garis.cpp
	g++ -c garis.cpp

pixel.o: pixel.cpp
	g++ -c pixel.cpp

clean:
	rm *o perspective
	
