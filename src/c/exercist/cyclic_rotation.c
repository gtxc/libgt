/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * An array A consisting of N integers is given. Rotation of the array means that each element is shifted
 * right by one index, and the last element of the array is moved to the first place. For example, the
 * rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index
 * and 6 is moved to the first place).
 *
 * The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.
 *
 * Assume that the following declarations are given:
 *
 * struct Results {
 *   int * A;
 *   int N; // Length of the array
 * };
 *
 * Write a function:
 *
 * struct Results solution(int A[], int N, int K);
 *
 * that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.
 *
 * For example, given
 *
 *  A = [3, 8, 9, 7, 6]
 *  K = 3
 *
 * the function should return [9, 7, 6, 3, 8]. Three rotations were made:
 *
 *  [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
 *  [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
 *  [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
 *
 *  For another example, given
 *
 *  A = [0, 0, 0]
 *  K = 1
 *
 *  the function should return [0, 0, 0]
 *
 *  Given
 *
 *  A = [1, 2, 3, 4]
 *  K = 4
 *
 * the function should return [1, 2, 3, 4]
 *
 * Assume that:
 * N and K are integers within the range [0..100];
 * each element of array A is an integer within the range [−1,000..1,000].
 * In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct Results {
    int *A;
    int N;
};

void print_int_array(int arr[], size_t size) {
    printf("[");
    for (unsigned long i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

struct Results cyclicRotation(const int A[], int N, int K) {
    struct Results r;
    int *tmp = malloc(sizeof *tmp * N);
    if (!tmp) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; ++i) {
        tmp[(i + K) % N] = A[i];
    }
    r.A = tmp;
    r.N = N;
    return r;
}

int main() {
    int A[] = {1,2,3,4,5};
    int size = sizeof A / sizeof A[0];
    struct Results result;
    result = cyclicRotation(A, size, 3);
    print_int_array(result.A, size);
    free(result.A);
    return 0;
}