all:  main city pik

main: main.o buffer.o garis.o point.o warna.o pixel.o bentuk.o badanHeli.o ekorHeli.o helikopter.o city_map.o polygon.o awan.o clip.o
	g++ -o main main.o buffer.o garis.o point.o warna.o pixel.o  bentuk.o badanHeli.o ekorHeli.o helikopter.o city_map.o polygon.o awan.o clip.o

city: main_city.o buffer.o garis.o point.o warna.o pixel.o bentuk.o badanHeli.o ekorHeli.o helikopter.o city_map.o
	g++ -o city main_city.o buffer.o garis.o point.o warna.o pixel.o bentuk.o badanHeli.o ekorHeli.o helikopter.o city_map.o

pik: mainPicker.o buffer.o garis.o point.o warna.o pixel.o bentuk.o badanHeli.o ekorHeli.o helikopter.o baling.o picker.o
	g++ -o pik mainPicker.o buffer.o garis.o point.o warna.o pixel.o bentuk.o badanHeli.o ekorHeli.o helikopter.o baling.o picker.o

clean_pik:
	rm *o pik
	
clean_city:
	rm *o city

clean_win:
	rm *o window

clean_peta:
	rm *o peta

clean_main:
	rm *o main
