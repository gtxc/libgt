/*
 * Created by gt on 1/17/22 - 11:45 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x{10}, y{20};
    cout << x << " " << y << endl;
    swap(&x, &y);
    cout << x << " " << y << endl;
    return 0;
}