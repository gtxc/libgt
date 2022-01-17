/*
 * Created by gt on 1/17/22 - 1:53 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
// without using below related functions are working
//#include <cstdlib>
//#include <ctime>
#include <random>

using namespace std;

int main() {
    srandom(time(nullptr));
    cout << random() % 100 << endl;

    cout << RAND_MAX << endl;
    cout << pow(2.0, 31) << endl;
    return 0;
}