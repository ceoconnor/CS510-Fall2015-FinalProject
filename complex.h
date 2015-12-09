#include<stdio.h>


typedef struct COMPLEX{
    long double x;
    long double y;
}Complex;
Complex mult2(Complex, Complex);
Complex add2(Complex, Complex);
Complex square(Complex);
Complex juliamap(Complex, Complex);
void complex_print(Complex);
void test(Complex, Complex, Complex, Complex);
