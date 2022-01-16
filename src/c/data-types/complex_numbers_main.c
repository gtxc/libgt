/*
 * Created by gt on 10/19/21 - 1:23 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <complex.h>

int main() {

    #ifdef __STDC_NO_COMPLEX__
        printf("Complex arithmetic is not supported.\n");
    #else
        printf("Complex arithmetic is supported.\n");

        float _Complex c; // does not require complex.h
        double complex cx = 1.0 + 3.0 * I;
        double complex cy = 1.0 - 4.0 * I;

        printf("cx = %.2f%+.2fi\n", creal(cx), cimag(cx));
        printf("cy = %.2f%+.2fi\n", creal(cy), cimag(cy));

        double complex cz = cx + cy;
        printf("cx + xy = %.2f%+.2fi\n", creal(cz), cimag(cz));
#endif


    return 0;
}