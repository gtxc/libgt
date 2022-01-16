/*
 * Created by gt on 10/19/21 - 1:14 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * a flexible array member can be declared only as the last member of a struct
 * each struct can contain at most one flexible array
 * a flexible array cannot be the only element of a struct
 * any struct containing a flexible array member cannot be a member of another struct
 * a struct with a flexible array member cannot be statically initialized
 * it must be allocated dynamically
 *
 * Torvald's quote:
 * "USING VLA'S IS ACTIVELY STUPID! It generates much more code, and much slower code
 * (and more fragile code), than just using a fixed key size would have done."
 * Linux kernel is free of VLA's and he's proud of that fact
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct s {
    int array_size;
    int array[];
};

int main() {
    // variable length array
    int n = 5;
    int arr[n];

#ifdef __STDC_NO_VLA__
    printf("Variable length arrays is not supported.\node_");
#else
    printf("Variable length arrays is supported.\n");
#endif

    int desired_size = 5;
    struct s *p;
    p = malloc(sizeof (struct s) + desired_size * sizeof (int));
    if (!p) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    free(p);
    return 0;
}