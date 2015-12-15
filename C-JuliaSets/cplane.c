#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"

// Constructor that initializes the complex plane in a sensible way.
CPLANE new_cp(const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INDEX xpoints, const INDEX ypoints){
    CPLANE m;
    m.xpoints = xpoints;
    m.ypoints = ypoints;
    m.xmin = xmin;
    m.xmax = xmax;
    m.ymin = ymin;
    m.ymax = ymax;

    VALUE incx = (xmax-xmin)/xpoints;
    VALUE incy = (ymax-ymin)/ypoints;
    if (m.mat == NULL){
        fprintf(stderr, "Failed to allocate new_cplane\n");
    }
    
    // Initializes the complex numbers to create the complex plane.
    INDEX rows, cols;
    Complex n;
    // xpoints are the rows and ypoints are the columns.
    for (rows = 0; rows < ypoints; rows++){
        for (cols = 0; cols < xpoints; cols++){
            n.x = xmin + cols * incx;
            n.y = ymin + rows * incy;
            set(&m, rows, cols, n);
        }
    }
    
    return m;
}

void delete_cp(CPLANE m) {
    // Free memory that was allocated to avoid memory leak.
    free(m.mat);
}

void set(CPLANE *m, const INDEX row, const INDEX col, const Complex n){
    // Find the pointer to the block of memory contating the matrix mat,
    // then jump forward row number of rows and col number of columns.
    // Inside that block of memory insert the complex number n.
    if (row < 0 || col < 0 || row >= m->ypoints || col >= m->xpoints){
        fprintf(stderr, "ERROR: indexing matrix outside bounds");
        return;
    }
    *(m->mat + (m->xpoints * row) + col) = n;
}

Complex get(const CPLANE *m, const INDEX row, const INDEX col){
    // Find the pointer to the block of memory containing the matrix mat,
    // then jump forward row number of rows and col number of columns.
    // Return the complex number inside.
    return *(m->mat + (m->xpoints * row) + col);
}

// Abstraction layer in case implementation of Complex changes.
void print_complex(const Complex n){
    complex_print(n);
}

// Prints the complex plane seperated by tabs with each row on a serperate line.
void print_cplane(const CPLANE *m){
    INDEX r, c, maxr, maxc;
    maxr = m->ypoints;
    maxc = m->xpoints;
    
    for (r = 0; r < maxr ; r++){
        for(c = 0; c < maxc; c++){
            print_complex(get(m, r, c));
            printf(" ");
        }
        puts("");
    }
    puts("");
}