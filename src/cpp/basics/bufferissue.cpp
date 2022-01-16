/*
 * Created by gt on 1/13/22 - 9:54 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 */

#include <iostream>
using namespace std;

int main() {
    int i;
    double d;
    // if you enter a double for integer, remainder of integer will directly assign to double
    cout << "Enter an integer: ";
    cin >> i;
    cout << "Enter a double: ";
    cin >> d;
    cout << endl << "integer: " << i << ", double: " << d << endl;

    return 0;
}