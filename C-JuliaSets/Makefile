CC=gcc
CFLAGS=-g -02
LDLIBS=-lm
DEPS = complex.h cplane.h
OBJ = julia.o complex.o cplane.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

julia: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

run: julia 
	 ./julia
clean:
	$(RM) julia *.o *~


