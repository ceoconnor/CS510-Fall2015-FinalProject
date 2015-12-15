#ifndef cplane_hpp
#define cplane_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <vector>

// Includes proper namespaces to simplify code
using namespace std;
using namespace boost::numeric::ublas;

// Define types as abstraction layer to protect against implementation changes.
typedef unsigned long int INDEX;
typedef long double VALUE;

class CPLANE{
private:
    VALUE xmin;
    VALUE xmax;
    VALUE ymin;
    VALUE ymax;
    INDEX xpoints;
    INDEX ypoints;
    matrix<std::complex<long double> > mat;
public:
    matrix<std::complex<long double> > new_cp(VALUE, VALUE, VALUE, VALUE, INDEX, INDEX);
    std::complex<long double> get_cp(matrix<std::complex<long double>, INDEX, INDEX)
};



#endif /* cplane_hpp */
