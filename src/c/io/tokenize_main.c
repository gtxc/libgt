/*
 * Created by gt on 10/14/21 - 9:11 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>

int main() {
    char str[80] = "Hello how are you - my name is - gt";
    const char s[2] = "-";
    char *token;

    token = strtok(str, s);
    printf("%s\n", token);

    while (token) {
        // change below order to prevent SIGSEGV
        // investigate why this happens
        printf("%s\n", token);
        token = strtok(NULL, s);
    }

    return 0;
}