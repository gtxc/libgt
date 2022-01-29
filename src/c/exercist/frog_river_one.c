/*
 * Created by gt on 1/28/22 - 2:26 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>

int solution(int X, int A[], int N) {
    int i;
    int arr[X+1];
    int xsum = X * (X+1) / 2;
    for (int j = 0; j < X+1; ++j) {
        arr[j] = 0;
    }
    for (i = 0; i < N; ++i) {
        ++arr[A[i]];
        if (arr[A[i]] == 1) {
            xsum -= A[i];
        }
        if (xsum == 0) {
            return i;
        }
    }
    return -1;
}

int main() {
    int A[] = {1, 3, 1, 4, 2, 3, 5, 4};
    int size = sizeof A / sizeof A[0];
    int X = 5;
    printf("Earliest time: %i\n", solution(X, A, size));
    return 0;
}
