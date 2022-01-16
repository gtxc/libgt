/*
 * Created by gt on 1/14/22 - 1:13 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * arrays are static in size
 * vector is a type of dynamic array in C++
 *  it is an Object Oriented Template Class
 *  container in the C++ Standard Template Library
 *  can grow and shrink in size at execution time
 *  provides similar semantics and syntax as arrays
 *  very efficient
 *  can provide bounds checking
 *  can use lots of functions like sort, reverse, find, etc.
 *
 */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // optional initialization with constructor type
    // all elements are set to zero automatically
    vector <char> list (3);
    list[0] = 'g';  // array like assign
    list.at(0) = 'e';   // vector like assign

    // add new element end of the vector
    list.push_back('z');
    cout << list.at(list.size() - 1) << endl;
    cout << list.size();

    // 2D vector
    vector <vector <int>> two_d;
    return 0;
}