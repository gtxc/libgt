/*
 * Created by gt on 1/28/22 - 12:05 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * An array A consisting of N different integers is given. The array contains integers in the
 * range [1..(N + 1)], which means that exactly one element is missing.
 *
 * Your goal is to find that missing element.
 *
 * Write a function:
 *
 * int solution(int A[], int N);
 *
 * that, given an array A, returns the value of the missing element.
 *
 * For example, given array A such that:
 *
 *   A[0] = 2
 *   A[1] = 3
 *   A[2] = 1
 *   A[3] = 5
 * the function should return 4, as it is the missing element.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N is an integer within the range [0..100,000];
 * the elements of A are all distinct;
 * each element of array A is an integer within the range [1..(N + 1)].
 *
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
