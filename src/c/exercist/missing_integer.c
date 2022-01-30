/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 * This is a demo task.
 *
 * Write a function:
 *
 * int solution(int A[], int N);
 *
 * that, given an array A of N integers, returns the smallest positive integer (greater than 0)
 * that does not occur in A.
 *
 * For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 *
 * Given A = [1, 2, 3], the function should return 4.
 *
 * Given A = [-1, -3], the function should return 1.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N is an integer within the range [1..100,000];
 * each element of array A is an integer within the range [-1,000,000..1,000,000].
 *
 */

#include <stdio.h>
#include <stdlib.h>

int solution(const int A[], int N) {
    int *arr = calloc(N+2, sizeof *arr);
    int result = 1;
    for (int i = 0; i < N; ++i) {
        if (A[i] > 0 && A[i] <= N) {
            ++arr[A[i]];
        }
    }

    for (int i = 1; i < N+2; ++i) {
        if (arr[i] == 0) {
            result = i;
            break;
        }
    }
    free(arr);
    return result;
}

int main() {
    int A[] = {1,2,3,4,5};
    int size = sizeof A / sizeof A[0];
    printf("missing integer: %i\n", solution(A, size));
    return 0;
}