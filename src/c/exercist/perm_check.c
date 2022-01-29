/*
 * Created by gt on 1/29/22 - 5:09 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * A non-empty array A consisting of N integers is given.
 *
 * A permutation is a sequence containing each element from 1 to N once, and only once.
 *
 * For example, array A such that:
 *
 *     A[0] = 4
 *     A[1] = 1
 *     A[2] = 3
 *     A[3] = 2
 * is a permutation, but array A such that:
 *
 *     A[0] = 4
 *     A[1] = 1
 *     A[2] = 3
 * is not a permutation, because value 2 is missing.
 *
 * The goal is to check whether array A is a permutation.
 *
 * Write a function:
 *
 * int solution(int A[], int N);
 *
 * that, given an array A, returns 1 if array A is a permutation and 0 if it is not.
 *
 * For example, given array A such that:
 *
 *     A[0] = 4
 *     A[1] = 1
 *     A[2] = 3
 *     A[3] = 2
 * the function should return 1.
 *
 * Given array A such that:
 *
 *     A[0] = 4
 *     A[1] = 1
 *     A[2] = 3
 * the function should return 0.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N is an integer within the range [1..100,000];
 * each element of array A is an integer within the range [1..1,000,000,000].
 *
 */

#include <stdio.h>

int solution(int A[], int N) {
//    int sum = N * (N+1) / 2;
//    int sum_A = 0;
    int counter = 0;
    int map[N+1];
    for (int i = 0; i < N+1; ++i) {
        map[i] = 0;
    }
    for (int i = 0; i < N; ++i) {
        if (A[i] > N) {
            return 0;
        }
        ++map[A[i]];
        if (map[A[i]] == 1) {
            ++counter;
        } else if (map[A[i]] > 1) {
            return 0;
        }
    }
    return counter == N ? 1 : 0;
}

int main() {
    int A[] = {1,2,3,4,5,6};
    int size = sizeof A / sizeof A[0];
    printf("result: %i\n", solution(A, size));

    return 0;
}
