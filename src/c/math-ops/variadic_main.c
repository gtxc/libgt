/*
 * Created by gt on 11/17/21 - 1:39 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
double average(double v1, double v2, ...);

int main() {
    double v1 = 10.5, v2 = 2.5;
    int num1 = 6, num2 = 5;
    long num3 = 12L, num4 = 20L;

    printf("Average = %.2lf\n", average(v1, 3.5, v2, 4.5, 0.0));
    printf("Average = %.2lf\n", average(1.0, 2.0, 0.0));
    printf("Average = %.2lf\n", average((double) num2, v2, (double) num1, (double) num3, (double) num4, 0.0));
    return 0;
}