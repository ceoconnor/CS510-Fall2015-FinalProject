#include "complex.h"

// Define types as abstraction layer to protect against implementation changes.
typedef unsigned long int INDEX;
typedef long double VALUE;

// Use abstract types inside matrix definition for robustness.
typedef struct CPLANE {
    VALUE xmin;
    VALUE xmax;
    VALUE ymin;
    VALUE ymax;
    INDEX xpoints;
    INDEX ypoints;
    Complex *mat;
} CPLANE;

// Constructor that initializes type in sensible way.
CPLANE new_cp(const VALUE, const VALUE, const VALUE, const VALUE, const INDEX, const INDEX);

// Destructor to free up allocated memory.
void delete_cp(CPLANE);

// Setter for individual complex numbers in the complex plane.
void set(CPLANE *, const INDEX, const INDEX, const Complex);

// Getter for individual complex numbers in the complex plane.
Complex get(const CPLANE *, const INDEX, const INDEX);
