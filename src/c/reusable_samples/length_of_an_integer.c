/*
 * Created by gt on 1/20/22 - 12:11 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>

int length_of_an_integer(int n) {
    int length = 1;
    while (n /= 10) ++length;
    return length;
}

int main() {
    printf("length of the integer is: %i\n", length_of_an_integer(9));
    return 0;
}