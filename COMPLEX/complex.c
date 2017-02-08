#include "complex.h"
struct complex complex_add(struct complex c1,struct complex c2)
{
    struct complex sum;
    sum.real = c1.real + c2.real;
    sum.imag = c1.imag + c2.imag;
    return sum;
};
