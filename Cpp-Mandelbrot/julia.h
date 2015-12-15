
#ifndef julia_hpp
#define julia_hpp

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <complex>

// Define types as abstraction layer to protect against implementation changes.
typedef long double VALUE;
typedef std::complex<long double> COMP;

// Multiplies two complex numbers together and returns their product.
COMP mult2(COMP, COMP);

// Adds two complex numbers together and returns their sum.
// Used to add z^2 to c in the juliamap.
COMP add2(COMP, COMP);

// Squares two complex numbers together and returns the result.
// Used to create the complex number z in the juliamap.
COMP square(COMP);

// Combines the complex numbers z^2 and c to create the complex numbers
// that will form the complex plane.
COMP juliamap(COMP, COMP);




#endif /* julia_hpp */
