all:  main polygon peta

main: main.o buffer.o garis.o point.o warna.o pixel.o polygon.o clip.o peta.o
	g++ -o main main.o buffer.o garis.o point.o warna.o pixel.o polygon.o clip.o peta.o

polygon: driverPolygon.o buffer.o garis.o point.o warna.o pixel.o polygon.o clip.o peta.o
	g++ -o polygon driverPolygon.o buffer.o garis.o point.o warna.o pixel.o polygon.o clip.o peta.o

peta: main_peta.o buffer.o garis.o point.o warna.o pixel.o polygon.o clip.o peta.o
	g++ -o peta main_peta.o buffer.o garis.o point.o warna.o pixel.o polygon.o clip.o peta.o

clean_peta:
	rm *o peta

clean_win:
	rm *o window

clean_polygon:
	rm *o polygon

clean_main:
	rm *o main
