/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <math.h>

int bin_to_dec(long long bin) {
    int remainder, result = 0, i = 0;
    while (bin) {
        remainder = (int) (bin % 10);
        bin /= 10;
        result += remainder * (int) pow(2,i);
        ++i;
    }
    return result;
}