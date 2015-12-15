CC=g++
CFLAGS=-g -02
LDLIBS=-lm
DEPS = cplane.hpp julia.h
OBJ = julia.o cplane.o mandelbrot.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mandelbrot: $(OBJ)
	g++ -o $@ $^ $(CFLAGS)

run: mandelbrot 
	 ./mandelbrot
clean:
	$(RM) mandelbrot *.o *~
