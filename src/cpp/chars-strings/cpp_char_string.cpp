/*
 * Created by gt on 1/14/22 - 4:31 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * C++ Strings
 * std namespace
 * contiguous in memory
 * dynamic size
 * work with input and output streams
 * lots of useful member functions
 * operators can be used (+, =, <, etc.)
 * can be easily converted C-style strings
 * safer
 */

#include <string>
#include <iostream>

using namespace std;

int main() {
        // declaration and initialization
    string s1;
    string s2 {"gt"};
    string s3 {s2};
    string s4 {"Gurkan", 3}; // Gur
    string s5 {s3, 0, 2}; // Gu
    string s6 (3, 'X'); // XXX
    string s7 {5, 'G'}; // not the same as above
    cout << s7 << endl;
    cout << s6 << endl;

    // assignment
    s1 = "foo bar";
    s2 = s1;
    string part1 = "C++";
    string part2 = "is a powerful";
    string sentence;
    sentence = part1 + " " + part2 + " language";
    cout << sentence << endl;

    cout << s2[0] << endl;
    cout << s2.at(0) << endl;

    s2[0] = 'g';
    s2.at(0) = 'p';

    cout << s2 << endl;

    for (auto c : sentence) {
        cout << c;
        cout << " ";
    }
    cout << endl;

    string ss {"This is a test"};
    cout << ss.substr(0, 4) << endl;

    // returns the first occurrence of the given string if it is found
    // if not returns npos which is the greatest possible value for an element of size_t (no position)
    cout << ss.find("This") << endl;
    cout << ss.find("this") << endl;
    cout << ss.find("is a", 6) << endl; // searches after 6th index
    // rfind() : reverse find
    // erase(start_index, length)
    // clear() : removes all the characters
    // length()
    // s += "Some string"
    // getline(cin, str); // reads entire line until \n
    // getline(cin, str, 'x'); // reads until the character x
    string xxx;
    cout << "Enter something, terminate wiht 'x': ";
    getline(cin, xxx, 'x');
    cout << "You entered: " + xxx << endl;
    // cin >> s; accepts up to the first space character
    string s10 (10, 'X');
    cout << s10 << endl;
    return 0;
}
