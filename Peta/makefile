all: window peta main

clip: mainClip.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o clip.o peta.o scanline.o fill.o
	g++ -o clip mainClip.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o clip.o peta.o scanline.o fill.o


window: mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o window mainWindow.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o

peta: mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o
	g++ -o peta mainPeta.o buffer.o peta.o garis.o point.o warna.o pixel.o bentuk.o	

main: main.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o peta.o
	g++ -o main main.o buffer.o window.o garis.o point.o warna.o pixel.o bentuk.o peta.o

city: main_city.o buffer.o garis.o point.o warna.o pixel.o bentuk.o city_map.o
	g++ -o city main_city.o buffer.o garis.o point.o warna.o pixel.o bentuk.o city_map.o

clean_win:
	rm *o window

clean_peta:
	rm *o peta

clean_main:
	rm *o main
