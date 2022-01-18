/*
 * Created by gt on 1/17/22 - 11:45 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// pass by reference is useful even if you do not modify the element passed to function
// by doing so, element is not copied by function, it directly reaches to the element by reference
// to avoid storage and copy overhead
// by implementing item passed to function as const, it is possible to avoid unwanted modify operations
void print_vector(const vector<int> &v) {
    for (auto item : v) {
        cout << item << endl;
    }
}

int main() {
    int x{10}, y{20};
    cout << x << " " << y << endl;
    swap(x, y);
    cout << x << " " << y << endl;

    vector<int> data {1,2,3,4,5};
    print_vector(data);
    return 0;
}