<<<<<<< HEAD
all: window peta

window: mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o window mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o

peta: mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o peta mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o	

clean_win:
	rm *o window

clean_peta:
	rm *o peta
=======
all: window peta main

window: mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o window mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o

peta: mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o peta mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o	

main: main.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o peta.o
	g++ -o main main.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o peta.o

clean_win:
	rm *o window

clean_peta:
	rm *o peta

clean_main:
	rm *o main
>>>>>>> 89d67ea23653560b473c76e0ad09c051d5706a08
