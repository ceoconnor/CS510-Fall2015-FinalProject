#include "julia.h"
#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <complex>

// Multiplies two complex numbers together and returns their product.
COMP mult2(COMP a, COMP b){
    COMP v;
    v = a * b;
    return v;
}

// Adds two complex numbers together and returns their sum.
// Used to add z^2 to c in the juliamap (mandelbrot).
COMP add2(COMP a, COMP b){
    COMP v;
    v = a + b;
    return v;
}

// Squares two complex numbers together and returns the result.
// Used to create the complex number z in the juliamap (mandelbrot).
COMP square(COMP a){
    COMP v;
    v = (a*a);
    return v;
}

// Combines the complex numbers z^2 and c to create the complex numbers
// that will form the complex plane.
COMP juliamap(COMP z, COMP c){
    COMP v;
    v = add2(square(z), c);
    return v;
}
