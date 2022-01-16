/*
 * Created by gt on 10/19/21 - 1:50 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * int arr[100] = {1, 2, 3} // initializes first 3 elements, rest assigned to 0
 * int arr[50] = {[1] = 12, 4, 5, 6 [12] = 12}
 *
 */

#include <stdio.h>

struct point {
    int x, y;
};

int main() {
    int a[6] = {[4] = 2, [1] = 14}; // a[6] = {0, 14, 0, 0, 2, 0}
    int b[4] = {[3]13, [0]24};
    printf("%i\n", b[4]);
    int c[100] = {[0 ... 19] = 3, [56 ... 67] = 11};
    printf("%i\n", c[14]);

    struct point p = {.y = 2, .x = 5};
    struct point q = {y: 2, x: 5};
    printf("%i\n", q.x);
    return 0;
}