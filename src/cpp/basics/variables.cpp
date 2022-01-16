/*
 * Created by gt on 1/13/22 - 10:34 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
using namespace std;

int main() {

    // data types
    int a;
    float b;
    double c;
    char d;
    bool e;
    string f;

    cout << "sizeof e: " << sizeof e << endl;
    cout << "sizeof f: " << sizeof f << endl;
    cout << "f.size(): " << f.size() << endl;


    // declaring
    int aa = 21;    // C-like
    int bb (21);    // Constructor
    int cc {21};    // C++11 list, catches overflow

    return 0;
}