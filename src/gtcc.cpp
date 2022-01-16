/*
 * Created by gt on 1/16/22 - 5:56 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srandom(time(nullptr));
    cout << random() % 100 << endl;

    return 0;
}