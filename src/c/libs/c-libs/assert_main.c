/*
 * Created by gt on 11/19/21 - 1:15 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <limits.h>

// available in C11
//static_assert(CHAR_BIT == 16, "16-bit char falsely assumed");

int main() {
    double x, y, z;
    puts("Enter a pair of numbers (0 0 to quit): ");
    while (scanf("%lf%lf", &x, &y) == 2 && (x != 0 || y != 0)) {
        z = x * x - y * y;
        assert(z >= 0);
        printf("answer is %f\n", sqrt(z));
        puts("Next pair of numbers: ");
    }
    puts("Done");
    return 0;
}