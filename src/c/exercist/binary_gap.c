/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int binarygap(int N) {
    int gap = 0;
    int max_gap = 0;
    int one_found = 0;
    while (N) {
        if (N & 1) {
            one_found = 1;
            max_gap = gap > max_gap ? gap : max_gap;
            gap = 0;
        } else {
            gap = one_found ? gap+1 : gap;
        }
        N >>= 1;
    }
    return max_gap;
}

int main() {
    printf("%i\n", binarygap(1376796946));
    return 0;
}
