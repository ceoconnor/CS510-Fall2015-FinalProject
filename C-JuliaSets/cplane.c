#include <stdio.h>
#include <stdlib.h>
#include "cplane.h"

// Constructor that initializes matrix in a sensible way
MATRIX new_matrix(const VALUE xmin, const VALUE xmax, const VALUE ymin, const VALUE ymax, const INDEX xpoints, const INDEX ypoints) {
  MATRIX m;
  m.rows = xpoints;
  m.cols = ypoints;
  m.mat = (VALUE *)calloc(rows * cols, sizeof(VALUE));
  if (m.mat == NULL) {
    fprintf(stderr, "Failed to allocate new_matrix\n");
  }
  return m;
}

void delete_matrix(MATRIX m) {
  // Free memory that was allocated, to avoid memory leak
  free(m.mat);
}

void set(MATRIX *m, const INDEX xpoints, const INDEX ypoints, const VALUE v) {
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Inside that block of memory
  // insert the value v.
  if (row < 0 || col < 0 || row >= m->rows || col >= m->cols) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return;
  }
  *(m->mat + (m->cols * row) + col) = v;
}

VALUE get(const MATRIX *m, const INDEX xpoints, const INDEX ypoints) {
  // Find the pointer to the block of memory containing 
  // the matrix mat, then jump forward row number of rows
  // and col number of columns.  Return the value inside.
  if (row < 0 || col < 0 || row >= m->rows || col >= m->cols) {
    fprintf(stderr, "ERROR: indexing matrix outside bounds");
    return 0;
  }
  return *(m->mat + m->cols * row + col);
}

// Abstraction layer in case implementation of VALUE changes later
void print_value(const VALUE v) {
  printf("%Lf", v);
}

void print_matrix(const MATRIX *m) {
  INDEX r, c, maxr, maxc;
  maxr = m->rows;
  maxc = m->cols;

  printf("Matrix (rows: %d, cols: %d) \n", maxr, maxc);
  for(r=0; r<maxr; r++) {
    for(c=0; c<maxc; c++) {
      // print values of matrix separated by tabs
      // with each row on a separate line
      print_value(get(m, r, c));
      printf(" ");
    }
    puts("");
  }
  puts("");
}

