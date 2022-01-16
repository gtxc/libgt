/*
 * Created by gt on 10/20/21 - 10:38 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int bin_to_dec(long long bin);

long long int dec_to_bin(int dec);

int main() {

    int g = 0b111;
    printf("%i\n", g);

    long long int bin = 0b00011001;
    long long int n = 11001;
    printf("%lli\n", bin);
    printf("%i\n", bin_to_dec(n));

    printf("%i\n", 0101);

    printf("%lli\n", dec_to_bin(2047));

    printf("%i\n", ~0b110);
    return 0;
}