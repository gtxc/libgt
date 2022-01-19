/*
 * Created by gt on 1/19/22 - 3:07 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>

using namespace std;

int main() {
    int *int_ptr {nullptr};
    int_ptr = new int; // new keyword allocates an integer on the heap
    cout << *int_ptr << endl;

    delete int_ptr; // frees the allocated storage
    cout << *int_ptr << endl;

    int *array_ptr {nullptr};
    int size {};
    cout << "Element size for array: ";
    cin >> size;
    array_ptr = new int[size];
    delete [] array_ptr;
}