/*
 * Created by gt on 1/28/22 - 12:57 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

void print_int_array(int arr[], size_t size) {
    printf("[");
    for (unsigned long i = 0; i < size; ++i) {
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
