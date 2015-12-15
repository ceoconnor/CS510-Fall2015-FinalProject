#include "cplane.hpp"
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

// Initializes the complex plane.
CPLANE::new_cp(VALUE Xmin, VALUE Xmax, VALUE Ymin, VALUE Ymax, INDEX Xpoints, INDEX Ypoints){
    xmin = Xmin;
    xmax = Xmax;
    ymin = Ymin;
    ymax = Ymax;
    xpoints = Xpoints;
    ypoints = Ypoints;
    VALUE incx = (xmax-xmin)/xpoints;
    VALUE incy = (ymax-ymin)/ypoints;
    
    MATR mat(xpoints,ypoints);
    
    int i, j;
    VALUE x, y;
    
    // Fill the complex plane
    for (x = xmin; i < xpoints; x = x + incx){
        for (y = ymin; j < ypoints; y = y + incy){
            mat(i,j) = COMP(x,y);
            j++;
        }
        i++;
    }
    return mat;
};

// Gets the values in the complex plane.
COMP CPLANE::get_cp(MATR mat, INDEX i, INDEX j){
    COMP m;
    m = mat(i,j);
    return m;
};
