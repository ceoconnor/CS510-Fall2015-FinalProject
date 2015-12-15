#include "cplane.hpp"

using namespace boost::numeric::ublas;

CPLANE::new_cp(VALUE Xmin, VALUE Xmax, VALUE Ymin, VALUE Ymax, INDEX Xpoints, INDEX Ypoints){
    xmin = Xmin;
    xmax = Xmax;
    ymin = Ymin;
    ymax = Ymax;
    xpoints = Xpoints;
    ypoints = Ypoints;
    VALUE incx = (xmax-xmin)/xpoints;
    VALUE incy = (ymax-ymin)/ypoints;
    
    matrix<std::complex<long double> > mat(xpoints,ypoints);
    
    int i, j;
    VALUE x, y;
    
    for (x = xmin; i < xpoints; x = x + incx){
        for (y = ymin; j < ypoints; y = y + incy){
            mat(i,j) = std::complex<long double>(x,y);
            j++;
        }
        i++;
    }
    return mat;
}

std::complex<long double> CPLANE::get_cp(matrix<std::complex<long double> > mat, INDEX row, INDEX col){
    
}