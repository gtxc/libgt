/*
 * Created by gt on 10/12/21 - 6:20 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int gcd_gt(int n1, int n2) {
    return !n1 ? n2 : gcd_gt(n2 % n1, n1);
}

int main() {
    int n1 = 120, n2 = 140;
    printf("GCD of %d and %d is %d\n", n1, n2, gcd_gt(n1, n2));
    return 0;
}