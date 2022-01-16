/*
 * Created by gt on 1/14/22 - 3:59 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <cctype> // ctype.h
#include <cstring> // string.h
#include <cstdlib> // stdlib.h
#include <iostream>

using namespace std;

int main() {
    cout << isalpha('a') << endl;
    cout << isalnum('a') << endl;
    cout << isdigit('a') << endl;
    cout << islower('a') << endl;
    cout << isprint('a') << endl;
    cout << ispunct('a') << endl;
    cout << isupper('a') << endl;
    cout << isspace('a') << endl;
    cout << tolower('a') << endl;
    cout << toupper('a') << endl;

    char str[80];
    strcpy(str, "gt");
    strcat(str, "orc");
    cout << strlen(str) << endl;
    cout << strcmp(str, "elf") << endl;

    char words[80];
    cout << "Write few words: ";
    cin.getline(words, 80);
    cout << "Words: " << words << endl;
}