/*
 * Created by gt on 1/16/22 - 5:37 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int a = 10;
    int b = 20;
    swap(&a, &b);
    printf("a: %i, b: %i\n", a, b);

    puts("This is the C file");

    srandom(time(NULL));
    long x = random() % 100;
    printf("random number: %li\n", x);

    return 0;
}