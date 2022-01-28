/*
 * Created by gt on 1/28/22 - 12:05 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>

int solution(const int A[], int N) {
    long result = ((long)(N+1) * (N+2)) / 2;
    for (int i = 0; i < N; ++i) {
        result -= (long)A[i];
    }
    return (int) result;
}

int main() {
    int A[] = {5, 3, 2, 6, 7, 8, 1, 9, 4};
    int size = sizeof A / sizeof A[0];
    printf("Missing element: %i\n", solution(A, size));

    return 0;
}
