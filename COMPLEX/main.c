#include <stdio.h>
#include <stdlib.h>
#include "complex.h"

int main(void)
{
        struct complex c1,c2,c3;
        int a = 5,b=8,c;
        c1.real = 5;
        c1.imag = 5;
        c2.real = 5;
        c2.imag = 5;
        c = SampleAddInt(a,b);
        c3 = complex_add(c1,c2);
        printf("the sum of c1 and c2 = %f + i%f",c3.real,c3.imag);
        printf(" c = %d",c);
	return 0;
}
