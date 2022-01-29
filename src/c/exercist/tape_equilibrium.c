/*
 * Created by gt on 1/28/22 - 12:57 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.
 *
 * Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ...,
 * A[P - 1] and A[P], A[P + 1], ..., A[N - 1].
 *
 * The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P - 1]) - (A[P] +
 * A[P + 1] + ... + A[N - 1])|
 *
 * In other words, it is the absolute difference between the sum of the first part and the sum of
 * the second part.
 *
 * For example, consider array A such that:
 *
 *   A[0] = 3
 *   A[1] = 1
 *   A[2] = 2
 *   A[3] = 4
 *   A[4] = 3
 * We can split this tape in four places:
 *
 * P = 1, difference = |3 - 10| = 7
 * P = 2, difference = |4 - 9| = 5
 * P = 3, difference = |6 - 7| = 1
 * P = 4, difference = |10 - 3| = 7
 * Write a function:
 *
 * int solution(int A[], int N);
 *
 * that, given a non-empty array A of N integers, returns the minimal difference that can be
 * achieved.
 *
 * For example, given:
 *
 *   A[0] = 3
 *   A[1] = 1
 *   A[2] = 2
 *   A[3] = 4
 *   A[4] = 3
 * the function should return 1, as explained above.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N is an integer within the range [2..100,000];
 * each element of array A is an integer within the range [-1,000..1,000].
 *
 */

#include <stdio.h>
#include <stdlib.h>

void print_int_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

int solution(int A[], int N) {
    int dif;
    int min_dif = 2000;
    int sum[N];
    sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
        sum[i] = sum[i-1] + A[i];
    }
    for (int P = 1; P < N; ++P) {
        dif = abs(sum[N - 1] - sum[P-1] - sum[P-1]);
        if (min_dif > dif) {
            min_dif = dif;
        }
        if (min_dif == 0) {
            break;
        }
    }
    return min_dif;
}

int main() {
    int A[] = {3, 1, 2, 4, 3};
    int size = sizeof A / sizeof A[0];
    printf("min difference: %i\n", solution(A, size));
    return 0;
}
