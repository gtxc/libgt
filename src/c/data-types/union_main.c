/*
 * Created by gt on 11/8/2021 - 15:15.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * user defined data type like struct
 *
 */

#include <stdio.h>

union mixed {
    char c;
    float f;
    int i;
};

int main() {

    union mixed x = {.i = 17};

    union mixed *y;
    y = &x;
    y->c = 'g';

    x.c = 'c';
    x.i = 1;
    x.f = 2.3f;

    printf("char: %c\n", x.c);
    printf("int: %i\n", x.i);
    printf("float: %f\n", x.f);
    printf("sizeof x: %lu\n", sizeof x);

    return 0;
}