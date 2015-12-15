#!/bin/sh

// Bash code to generate output for juliaset and mandelbrot

./C-JuliaSets && make
./Cpp-Mandelbrot && make

./C-JuliaSets && ./julia -2 2 -2 2 1000 1000 -1.037 0.17 > juliaset.csv
./Cpp-Mandelbrots && ./mandelbrot -2 2 -2 2 1000 1000 > mandelbrot.csv
