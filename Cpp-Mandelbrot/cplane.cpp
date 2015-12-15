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
    
    INDEX i, j;
    VALUE x, y;
    
    // Fill the complex plane
    for (i = 0; i < xpoints; i++){
        for (j = 0; j < ypoints; j++){
            x = xmin + i * incx;
            y = ymin + j * incy;
            mat(i,j) = COMP(x,y);
        }
    }
    return mat;
};

// Gets the values in the complex plane.
COMP CPLANE::get_cp(MATR mat, INDEX i, INDEX j){
    COMP m;
    m = mat(i,j);
    return m;
};
