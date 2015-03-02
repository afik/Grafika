all: window peta

window: mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o window mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o

peta: mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o peta mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o	

clean_win:
	rm *o window

clean_peta:
	rm *o peta
