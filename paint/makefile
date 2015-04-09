polygon: mainPolygon.o polygon.o buffer.o garis.o pixel.o point.o warna.o persegi.o
	g++ -o polygon mainPolygon.o polygon.o buffer.o garis.o pixel.o point.o warna.o persegi.o

canvas: mainCanvas.o canvas.o polygon.o buffer.o garis.o bentuk.o pixel.o point.o warna.o persegi.o
	g++ -o canvas mainCanvas.o canvas.o polygon.o buffer.o garis.o bentuk.o pixel.o point.o warna.o persegi.o	 

paint: mouse.o pointer.o polygon.o buffer.o garis.o pixel.o point.o warna.o bentuk.o persegi.o lingkaran.o
	g++ -o paint mouse.o polygon.o pointer.o buffer.o garis.o pixel.o point.o warna.o bentuk.o persegi.o lingkaran.o

clean_canvas:
	rm *o canvas
	
clean:
	rm *o polygon

clean_paint:
	rm *o paint

