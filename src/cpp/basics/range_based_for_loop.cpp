/*
 * Created by gt on 1/14/22 - 3:05 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
using namespace std;

int main() {
    int arr[] {1,2,3,4};
    for (int item : arr) {
        cout << item << endl;
    }

    // compiler decides what the data type if auto is used
    for (auto item : "Gurkan") {
        cout << item << endl;
    }
    return 0;
}