/*
 * Created by gt on 11/23/21 - 11:17 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10

// available in C11
//static_assert(sizeof (double) == 2 * sizeof (int), "double not twice int size");

void show_array(const int ar[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%i ", ar[i]);
    }
    putchar('\n');
}

int main() {
    int values[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target[SIZE];
    double curious[SIZE / 2] = {2.0, 2.0e5, 2.0e10, 2.0e20, 5.0e30};
    puts("memcpy() used:");
    puts("values (original data): ");
    show_array(values, SIZE);
    memcpy(target, values, sizeof (int) * SIZE);
    puts("target (copy of values):");
    show_array(target, SIZE);

    puts("\nUsing memmove() with overlapping ranges:");
    memmove(values + 2, values, sizeof (int) * 5);
    puts("values -- elements 0-5 copied to 2-7:");
    show_array(values, SIZE);

    puts("\nUsing memcpy() to copy double to int:");
    memcpy(target, curious, sizeof (double) * (SIZE / 2));
    puts("target -- 5 doubles into 10 int positions:");
    show_array(target, SIZE / 2);
    show_array(target + 5, SIZE / 2);

    return 0;
}