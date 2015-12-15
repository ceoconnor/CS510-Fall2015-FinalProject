# CS510-Fall2015-FinalProject
## Cormac O'Connor

This repository contains my final project for CS 510 in Fall 2015. The folders included are: C-JuliaSets, Cpp-Mandelbrot and Datasets. The files included are generate_output.sh and plot_data.py.

C-JuliaSets contains the files and header files necessary to create Julia Sets in C programming language. The complex files contain C code that uses a complex structure to take complex numbers and multiply, add, square, and print them. It also has a function to create a juliamap point that is used in the cplane files. The cplane files create a complex plane by initializing an empty two-dimensional array (matrix) ready to be filled by complex numbers in incremental steps from (xmin, ymin) to (xpoints, ypoints). The julia file then creates the juliamap from the juliamap function and the complex plane. Finally, the Makefile compiles all the files and runs the code.

Cpp-Mandelbrots contains the files and header files necessary to create Mandelbrots in C++ programming language. Cpp essentially transforms the C-JuliaSets files from C files to C++ files. The complex plane is initialized by the cplane files while the julia files contain the functions necessary to compute the Mandelbrots (similar to complex files in C-JuliaSets). The mandelbrot file is similar to the julia file except that now it creates Mandelbrots instead of Julia Sets. Finally the Makfile compiles all the files and runs the code.

The generate_output.sh file executes the two Makefiles to build the programs, and then executes the programs with initial conditions and saves them to csv files.

The plot_data.py file should parse one command line argument that gives the name of a csv file and load it into a pandas dataframe. Then it should generate a 2D heatmapped plot using matplotlib and save the file to a JPEG (juliaset.jpeg, mandelbrot.jpeg).

Datasets contains high-resolution plots.

