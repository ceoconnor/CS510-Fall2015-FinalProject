//
//  cplane.hpp
//  
//
//  Created by Cormac O'Connor on 12/14/15.
//
//

#ifndef cplane_hpp
#define cplane_hpp

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
#include <vector>

using namespace std;
using namespace boost::numeric::ublas;
typedef unsigned long int INDEX;
typedef long double VALUE;

class CPLANE{
public:
    VALUE xmin;
    VALUE xmax;
    VALUE ymin;
    VALUE ymax;
    INDEX xpoints;
    INDEX ypoints;
    matrix<std::complex<long double> > mat;
    
    matrix<std::complex<long double> > set_cp(VALUE, VALUE, VALUE, VALUE, INDEX, INDEX);
    std::complex<long double> get(matrix<std::complex<long double>, INDEX, INDEX);
    void print_cplane(matrix<std::complex<long double>);
};



#endif /* cplane_hpp */
