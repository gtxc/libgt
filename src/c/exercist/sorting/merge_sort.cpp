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
 *
 *
 *
 */

#include <iostream>

using namespace std;

void print_int_array(int *A, int size) {
    cout << "[";
    for (int i = 0; i < size; ++i) {
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
}

void divide(int A[], int low, int high) {
    if (low >= high) {
        return;
    }
    int mid = (low + high) / 2;
    divide(A, low, mid);
    divide(A, mid+1, high);
    merge(A, low, mid, high);
}


int main() {
    int A[] = {3,2,1,5,8,0,7};
    int size = sizeof A / sizeof A[0];
    print_int_array(A, size);
    divide(A, 0, size);
    print_int_array(A, size);
    return 0;
}
