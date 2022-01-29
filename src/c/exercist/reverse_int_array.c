/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int  *reverseIntArray(int A[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        int tmp = A[i];
        A[i] = A[n - i - 1];
        A[n - i - 1] = tmp;
    }
    return A;
}

int main() {
    int *p;
    int a[] = {1,2,3,4,5};
    int n = sizeof a / sizeof a[0];
    p = reverseIntArray(a, n);
    for (int i = 0; i < n; ++i) {
        printf("%i %i - ", a[i], *p);
        ++p;
    }
    return 0;
}