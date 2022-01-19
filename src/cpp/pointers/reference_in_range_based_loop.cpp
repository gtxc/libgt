/*
 * Created by gt on 1/19/22 - 4:27 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <vector>

using namespace std;

void display(const vector<string>& vec) {
    for (const auto& item : vec) {
        cout << item + " ";
    }
    cout << endl;
}

int main(int argc, char **argv) {

    vector<string> foo {"gt", "elf", "orc"};
    display(foo);
    // no changes in vector
    for (auto item : foo) {
        item = "human";
    }
    display(foo);
    // also changes
    for (int i = 0; i < 3; ++i) {
        foo[i] = "sth";
    }
    display(foo);
    // changes in vector
    for (auto &item : foo) {
        item = "human";
    }
    display(foo);

    return 0;
}