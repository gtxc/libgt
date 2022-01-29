/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int solution(const int A[], int N) {
    int count = 1, aif = 0, zeros = 0;
    while (1) {
        for (int i = 0; i < N; ++i) {
            if (A[i] < 0) {
                ++zeros;
            }
            if (count != A[i]) {
                ++aif;
            }
        }
        if (zeros == N) {
            return 1;
        }
        zeros = 0;
        if (aif == N) {
            return count;
        } else {
            aif = 0;
        }
        ++count;
    }
}

int missingInteger(int A[], int N) {
    int *p = calloc(N + 1, sizeof (int));
    int i;
    for (i = 0; i < N; ++i)
    {
        if ((A[i] > 0) && (A[i] <= N))
        {
            ++p[A[i]];
        }
    }
    for (i = 1; i < N + 1; ++i)
    {
        if(p[i] == 0)
        {
            free(p);
            return i;
        }
    }
    free(p);

    return N + 1;
}

int main() {
    int arr[] = {1,2,3,4,5};
    printf("my sol = %i\n", solution(arr, 5));
    printf("oth sol = %i\n", missingInteger(arr, 5));
    return 0;
}