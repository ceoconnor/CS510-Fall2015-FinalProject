#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"


// Multiplies two complex numbers together and returns their product.
Complex mult2(Complex a, Complex b){
    Complex v;
    v.x = a.x * b.x - a.x * b.y;
    v.y = a.x * b.y + a.y * b.x;
    return v;
}

// Adds two complex numbers together and returns their sum.
// Used to add z^2 to c in the juliamap.
Complex add2(Complex a, Complex b){
    Complex v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return v;
}

// Squares two complex numbers together and returns the result.
// Used to create the complex number z in the juliamap.
Complex square(Complex a){
    Complex v;
    v.x = (a.x * a.x) - (a.y * a.y);
    v.y = 2 * a.x * a.y;
    return v;
}

// Combines the complex numbers z^2 and c to create the complex numbers
// that will form the complex plane.
Complex juliamap(Complex z, Complex c){
    Complex v;
    v = add2(square(z), c);
    return v;
}

// Prints out a complex number. Used later to print out the complex plane and juliamap.
void complex_print(Complex z){
    printf("%Lf + %Lfi", z.x, z.y);
}

