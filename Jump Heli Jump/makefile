all: city main

main: main.o buffer.o garis.o point.o warna.o pixel.o bentuk.o city_map.o awan.o clip.o helikopter.o badanHeli.o ekorHeli.o baling.o picker.o
	g++ -o main main.o buffer.o garis.o point.o warna.o pixel.o bentuk.o city_map.o awan.o clip.o helikopter.o badanHeli.o ekorHeli.o baling.o picker.o

city: main_city.o buffer.o garis.o point.o warna.o pixel.o bentuk.o city_map.o
	g++ -o city main_city.o buffer.o garis.o point.o warna.o pixel.o bentuk.o city_map.o

clean_win:
	rm *o window

clean_peta:
	rm *o peta

clean_main:
	rm *o main
