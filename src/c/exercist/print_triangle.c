/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

void printTriangle(int N) {
    for (int i = 1; i < N + 1; ++i) {
        for (int j = 0; j < i; ++j) {
            printf(" *");
        }
        printf("\n");
    }

    printf("\n");

    for (int i = N; i > 0; --i) {
        for (int j = 0; j < N - i; ++j) {
            printf("  ");
        }
        for (int j = 0; j < 2 * i - 1; ++j) {
            printf(" *");
        }
        printf("\n");
    }
}

int main() {
    printTriangle(5);
    return 0;
}