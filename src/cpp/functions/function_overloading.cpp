/*
 * Created by gt on 1/17/22 - 11:01 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(int num) {
    cout << "Printing int: " << num << endl;
}

void print(double num) {
    cout << "Printing double: " << num << endl;
}

void print(const string& s) {
    cout << "Printing string: " << s << endl;
}

void print(const string& s, const string& t) {
    cout << "Printing 2 strings " << s << " and " << t << endl;
}

void print(const vector<string>& v) {
    cout << "Printing vector of strings: ";
    for (const auto& i : v) {
        cout << i + " ";
    }
    cout << endl;
}

int main() {
    print(100);
    print('A'); // character is always promoted to int, should print 65 ASCII A
    print(123.5); // double
    print(123.3F); // float is promoted to double
    print("C-style string"); // C-style string is converted to a C++ string
    string s {"C++ string"};
    print(s); // C++ string
    print("C-style string", s); // first argument is converted to a C++ string
    vector<string> three_stooges {"Larry", "Moe", "Curly"};
    print(three_stooges);
    return 0;
}