/*
 * Created by gt on 10/21/21 - 4:26 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#define bsize 100

int f1() {
    return 1;
}

int f2() {
    return 2;
}

int main() {
    printf("sizeof _Bool: %li\n", sizeof (_Bool));

    char *text = malloc(sizeof *text * bsize);
    printf("Enter anything: ");
    while ((*text++ = (char) getchar()) != '\n')
        ; // null statement is needed as body of the while loop

    printf("text: %s\n", text);

    int sum = 0, i = 0;
    int data[20];
    while (i < 20)
        sum += data[i], i++; // comma operator

    /* comma operator */
    // this throws a warning and -Werror flag converts warnings into errors
//    int gg = (5, 10); // the value of gg is 10
    int gt = (f1(), f2()); // the value of gt is returning value of f2()
//    printf("gg is %i\n", gg);
    printf("gt is %i\n", gt);
    int y, z;
    int x = (y = 3, (z = ++y + 2) + 5); // value of x is 11;
    printf("x is %i\n", x);

    return 0;
}