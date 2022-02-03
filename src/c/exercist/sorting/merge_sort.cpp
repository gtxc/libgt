/*
 * Created by gt on 2/2/22 - 3:36 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 *
 *
 * [16,21,11,8,12,22] -> Merge Sort
 *
 * Yukarıdaki dizinin sort türüne göre aşamalarını yazınız.
 * Big-O gösterimini yazınız.
 *
 *      [3, 2, 1, 5, 8, 0, 7]
 *      [3, 2, 1, 5]
 *      [3, 2]
 *      [3]
 *      [2]
 *      [2, 3]
 *      [1, 5]
 *      [1]
 *      [5]
 *      [1, 5]
 *      [1, 2, 3, 5]
 *      [8, 0, 7]
 *      [8, 0]
 *      [8]
 *      [0]
 *      [0, 8]
 *      [7]
 *      [0, 7, 8]
 *      [0, 1, 2, 3, 5, 7, 8]
 *
 *  Time Complexity: O(n*log(n))
 */

#include <iostream>

using namespace std;

void print_int_array(int *A, int low,  int size) {
    cout << "[";
    for (int i = low; i < size; ++i) {
        if (i == size-1) cout << A[i];
        else cout << A[i] << ", ";
    }
    cout << "]" << endl;
}

void merge(int A[], int low, int mid, int high) {
    int tmp[high];
    int i = low;
    int j = mid+1;
    int k = low;

    while (i <= mid && j <= high) {
        if (A[i] <= A[j]) {
            tmp[k++] = A[i++];
        } else {
            tmp[k++] = A[j++];
        }
    }
    while (i <= mid) {
        tmp[k++] = A[i++];
    }
    while (j <= high) {
        tmp[k++] = A[j++];
    }
    for (k = low; k <= high; ++k) {
        A[k] = tmp[k];
    }
    // echo each step
    print_int_array(A, low, high+1);
}

void merge_sort(int A[], int low, int high) {
    // echo each step
    print_int_array(A, low, high+1);
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    merge_sort(A, low, mid);
    merge_sort(A, mid+1, high);
    merge(A, low, mid, high);
}

int main() {
    int A[] = {3,2,1,5,8,0,7};
    int size = sizeof A / sizeof A[0];
    merge_sort(A, 0, size-1);
    return 0;
}
