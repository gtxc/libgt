/*
 * Created by gt on 1/29/22 - 5:39 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * You are given N counters, initially set to 0, and you have two possible operations on them:
 *
 * increase(X) - counter X is increased by 1,
 * max counter - all counters are set to the maximum value of any counter.
 * A non-empty array A of M integers is given. This array represents consecutive operations:
 *
 * if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
 * if A[K] = N + 1 then operation K is max counter.
 * For example, given integer N = 5 and array A such that:
 *
 *     A[0] = 3
 *     A[1] = 4
 *     A[2] = 4
 *     A[3] = 6
 *     A[4] = 1
 *     A[5] = 4
 *     A[6] = 4
 * the values of the counters after each consecutive operation will be:
 *
 *     (0, 0, 1, 0, 0)
 *     (0, 0, 1, 1, 0)
 *     (0, 0, 1, 2, 0)
 *     (2, 2, 2, 2, 2)
 *     (3, 2, 2, 2, 2)
 *     (3, 2, 2, 3, 2)
 *     (3, 2, 2, 4, 2)
 * The goal is to calculate the value of every counter after all operations.
 *
 * Assume that the following declarations are given:
 *
 * struct Results {
 *   int * C;
 *   int L; // Length of the array
 * };
 *
 * Write a function:
 *
 * struct Results solution(int N, int A[], int M);
 *
 * that, given an integer N and a non-empty array A consisting of M integers, returns a sequence
 * of integers representing the values of the counters.
 *
 * Result array should be returned as a structure Results.
 *
 * For example, given:
 *
 *     A[0] = 3
 *     A[1] = 4
 *     A[2] = 4
 *     A[3] = 6
 *     A[4] = 1
 *     A[5] = 4
 *     A[6] = 4
 * the function should return [3, 2, 2, 4, 2], as explained above.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N and M are integers within the range [1..100,000];
 * each element results.C[A[i]]of array A is an integer within the range [1..N + 1].
 *
 */

#include <stdio.h>
#include <malloc.h>

void print_int_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

struct Results {
    int *C;
    int L; // Length of the array
};

struct Results solution(int N, int A[], int M) {
    struct Results results;
    results.L = N;
    results.C = calloc(N, sizeof *results.C);
    int max_cval = 0;
    int base_cval = 0;

    for (int i = 0; i < M; ++i) {
        if (A[i] <= N) {
            results.C[A[i]-1] = base_cval > results.C[A[i]-1] ? base_cval+1 : results.C[A[i]-1]+1;
            if (max_cval < results.C[A[i] - 1]) {
                max_cval = results.C[A[i] - 1];
            }
        } else {
            base_cval = max_cval;
        }
    }
    for (int i = 0; i < N; ++i) {
        if (results.C[i] < base_cval) {
            results.C[i] = base_cval;
        }
    }
    return results;
}

int main() {
    int A[] = {3,4,4,6,1,4,4};
    int M = sizeof A / sizeof A[0];
    int N = 5;
    struct Results results = solution(N, A, M);
    print_int_array(results.C, results.L);
    return 0;
}
