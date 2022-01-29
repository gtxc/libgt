/*
 * Created by gt on 1/17/22 - 11:34 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>

using namespace std;

void test(int arr[]) {
    // will not work since function takes the address of the first element
    // and further memory locations can have value other than zero
    while (*arr++) {
        cout << *arr << " ";
    }
    cout << endl;
}

// use const to not modify passed value accidentally
void print_int_array(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] {1,2,3,4};
    test(arr);
    print_int_array(arr, 4);
    return 0;
}