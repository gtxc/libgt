/*
 * Created by gt on 1/6/22 - 7:00 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <ctype.h>

void rate(int n, int atten) {
    unsigned char adch_tmp = 100 >> (atten / 2);
    adch_tmp = atten % 2 ? adch_tmp : adch_tmp + (adch_tmp >> 1);
    printf("atten:%3i, result: %i\n", atten, adch_tmp);
}

int main() {
    for (int i = 1; i < 12; ++i) {
        rate(100, i);
    }

    return 0;
}