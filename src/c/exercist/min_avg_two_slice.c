/*
 * Created by gt on 1/30/22 - 5:46 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
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

int solution(int A[], int N) {
    double min_avg = 10000.0;
    int start_index = 0;
    int *sum = calloc(N, sizeof *sum);
    for (int i = 0; i < N - 1; ++i) {
        int divider = 2;
        sum[i] = A[i];
        for (int j = i + 1; j < N; ++j) {
            sum[j] = sum[j - 1] + A[j];
            double avg = ((double) sum[j]) / divider;
            if (min_avg > avg) {
                min_avg = avg;
                start_index = i;
            }
            ++divider;
        }
    }
    free(sum);
    sum = NULL;
    return start_index;
}

// reduced time complexity
int MinAvgTwoSlice(int A[], int N) {
    int prefix_sum[N];
    prefix_sum[0] = A[0];
    for (int i = 1; i < N; ++i) {
        prefix_sum[i] = prefix_sum[i-1] + A[i];
    }
    int start_index2 = 0;
    int start_index3 = 0;
    double min_avg2 = ((double) prefix_sum[1]) / 2;
    double avg;
    for (int i = 2; i < N; ++i) {
        avg = ((double) prefix_sum[i] - prefix_sum[i-2]) / 2;
        if (min_avg2 > avg) {
            min_avg2 = avg;
            start_index2 = i - 1;
        }
        if (min_avg2 == 0) {
            break;
        }
    }
    double min_avg3 = ((double) prefix_sum[2]) / 3;
    for (int i = 3; i < N; ++i) {
        avg = ((double) prefix_sum[i] - prefix_sum[i-3]) / 3;
        if (min_avg3 > avg) {
            min_avg3 = avg;
            start_index3 = i - 2;
        }
        if (min_avg3 == 0) {
            break;
        }
    }
    return min_avg2 < min_avg3 ? start_index2 : start_index3;
}

int main() {
//    int A[] = {4, 2, 2, 5, 1, 5, 8};
//    int A[] = {5, 6, 3, 4, 9};
//    int A[] = {-3, -5, -8, -4, -10};
    int A[] = {1,1,-1,-1,1,1,-1,-1,1,1,1,1,1,1,-1,-1,-1,-1,-1};
    int size = sizeof A / sizeof A[0];
//    printf("result: %i\n", solution(A, size));
    printf("result: %i\n", MinAvgTwoSlice(A, size));
        return 0;
}
