/*
 * Created by gt on 1/27/22 - 2:51 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 *
 *
 * [22,27,16,2,18,6] -> Insertion Sort
 * Yukarı verilen dizinin sort türüne göre aşamalarını yazınız.
 * Big-O gösterimini yazınız.
 * Time Complexity: Average case: Aradığımız sayının ortada olması,Worst case: Aradığımız sayının sonda olması, Best case: Aradığımız sayının dizinin en başında olması.
 * Dizi sıralandıktan sonra 18 sayısı hangi case kapsamına girer? Yazınız.
 *
 * [7,3,5,8,2,9,4,15,6] dizisinin Insertion Sort'a göre ilk 4 adımını yazınız.
 *
 * 1.            [22, 27, 16, 2, 18, 6]
 *      1. step: [22, 27, 16, 2, 18, 6]
 *      2. step: [16, 22, 27, 2, 18, 6]
 *      3. step: [2, 16, 22, 27, 18, 6]
 *      4. step: [2, 16, 18, 22, 27, 6]
 *      5. step: [2, 6, 16, 18, 22, 27]
 *
 *
 * 2.   Best: O(n), Average: O(n^2), Worst: O(n^2)
 *
 * 3.   After sorting the array, 18 will be in the average case.
 *
 * 4.            [7, 3, 5, 8, 2, 9, 4, 15, 6]
 *      1. step: [3, 7, 5, 8, 2, 9, 4, 15, 6]
 *      2. step: [3, 5, 7, 8, 2, 9, 4, 15, 6]
 *      3. step: [3, 5, 7, 8, 2, 9, 4, 15, 6]
 *      4. step: [2, 3, 5, 7, 8, 9, 4, 15, 6]
 */

#include <stdio.h>

typedef unsigned long int u_long;

void print_int_array(int A[], size_t size) {
    printf("[");
    for (u_long i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", A[i]);
        else printf("%i, ", A[i]);
    }
    printf("]\n");
}

void insertion_sort(int A[], size_t size) {
    for (u_long i = 1; i < size; ++i) {
        u_long j;
        int tmp = A[i];
        for (j = i-1; j >= 0 && tmp < A[j]; --j) {
            A[j + 1] = A[j];
        }
        A[j + 1] = tmp;
        // echo each step
        printf("%li. step: ", i);
        print_int_array(A, size);
    }
}

int main() {
    int A[] = {22, 27, 16, 2, 18, 6};
//    int A[] = {7,3,5,8,2,9,4,15,6};
    size_t size_arr = sizeof A / sizeof A[0];
    print_int_array(A, size_arr);
    insertion_sort(A, size_arr);
    return 0;
}