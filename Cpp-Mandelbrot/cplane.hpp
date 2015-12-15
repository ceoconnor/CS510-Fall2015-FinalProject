#ifndef cplane_hpp
#define cplane_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

// Includes proper namespaces to simplify code.
using namespace std;
using namespace boost::numeric::ublas;

// Define types as abstraction layer to protect against implementation changes.
typedef unsigned long int INDEX;
typedef long double VALUE;
typedef std::complex<long double> COMP;
matrix<std::complex<long double> > MATR;

class CPLANE{
private:
    VALUE xmin;
    VALUE xmax;
    VALUE ymin;
    VALUE ymax;
    INDEX xpoints;
    INDEX ypoints;
    MATR mat;

public:
    // Constructor that initializes types in a sensible way.
    MATR new_cp(VALUE, VALUE, VALUE, VALUE, INDEX, INDEX);
    
    // Getter for individual complex numbers.
    COMP get_cp(MATR, INDEX, INDEX)
};



#endif /* cplane_hpp */
