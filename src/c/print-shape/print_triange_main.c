/*
 * Created by gt on 10/22/21 - 11:16 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int main() {
    int size = 9;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < 2 * size - 1; ++j) {
            if (j == (size + i - 1) || j == (size - i - 1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
    for (int i = 0; i < size * 2 - 1; ++i) {
        printf("*");
    }



    return 0;
}