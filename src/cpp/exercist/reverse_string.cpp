/*
 * Created by gt on 2/1/22 - 11:32 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>

using namespace std;

string reverse_string(string s) {
    string reverse {6};
    int length = (int) s.size();
    for (int i = 0; i < length; ++i) {
        reverse[length - 1 - i] = s[i];
    }
    cout << reverse << endl;
    return "gt";
}

int main() {
    reverse_string("gurkan");
    return 0;
}
