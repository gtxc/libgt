/*
 * Created by gt on 10/12/21 - 2:50 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int main() {
    int prime_array[50] = {2, 3};
    int prime_index = 1;
    _Bool is_prime;
    for (int i = 5; i < 101; i+=2) {
        is_prime = 1;
        for (int j = 1; i / prime_array[j] >= prime_array[j] ; ++j)
            if (i % prime_array[j] == 0)
                is_prime = 0;

        if (is_prime) {
            prime_array[++prime_index] = i;
        }
    }

    for (int i = 0; i < prime_index; ++i) {
        printf("%i ", prime_array[i]);
    }
    return 0;
}