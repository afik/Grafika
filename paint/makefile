polygon: mainPolygon.o polygon.o buffer.o garis.o pixel.o point.o warna.o 
	g++ -o polygon mainPolygon.o polygon.o buffer.o garis.o pixel.o point.o warna.o

canvas: mainCanvas.o canvas.o polygon.o buffer.o garis.o bentuk.o pixel.o point.o warna.o
	g++ -o canvas mainCanvas.o canvas.o polygon.o buffer.o garis.o bentuk.o pixel.o point.o warna.o	 

paint: mouse.o pointer.o polygon.o buffer.o garis.o pixel.o point.o warna.o bentuk.o
	g++ -o paint mouse.o polygon.o pointer.o buffer.o garis.o pixel.o point.o warna.o bentuk.o

clean_canvas:
	rm *o canvas
	
clean:
	rm *o polygon

clean_paint:
	rm *o paint

