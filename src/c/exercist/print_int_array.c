/*
 * Created by gt on 1/28/22 - 1:33 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>

void print_int_array(int arr[], size_t size) {
    printf("[");
    for (unsigned long i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

int main() {
    int A[] = {1,2,3,4,5,6};
    int size = sizeof A / sizeof A[0];
    print_int_array(A, size);
    return 0;
}
