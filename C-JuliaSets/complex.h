// Define types as abstraction layer to protect against implementation changes.
typedef long double VALUE;

// Use abstract types inside complex definition for robustness.
typedef struct COMPLEX {
    VALUE x;
    VALUE y;
}Complex;

// Multiplies two complex numbers together and returns their product.
Complex mult2(Complex, Complex);

// Adds two complex numbers together and returns their sum.
// Used to add z^2 to c in the juliamap.
Complex add2(Complex, Complex);

// Squares two complex numbers together and returns the result.
// Used to create the complex number z in the juliamap.
Complex square(Complex);

// Combines the complex numbers z^2 and c to create the complex numbers
// that will form the complex plane.
Complex juliamap(Complex, Complex);

// Prints out a complex number. Used later to print out the complex plane and juliamap.
void complex_print(Complex);

