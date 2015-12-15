#include <stdio.h>
#include "julia.h"
#include "cplane.cpp"
#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <complex>

int main (int argc, char **argv){
    // Checks to see if the paramters are correct. Should be 7 (-creal & cimag)
    if(argc < 7){
        fprintf(stderr, "ERROR: Parameters are not set correctly!");
        return 1;
    }
    
    // Initialize the parameters
    VALUE xmin = atoi(argv[1]);
    VALUE xmax = atoi(argv[2]);
    VALUE ymin = atoi(argv[3]);
    VALUE ymax = atoi(argv[4]);
    INDEX xpoints = atoi(argv[5]);
    INDEX ypoints = atoi(argv[6]);
    int MAXITER = 256;
