/*
 * Created by gt on 11/19/21 - 1:48 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

void sign_off(void);
void too_bad(void);

int main() {
    int n;
    // will be called when the program terminates with return 0
    atexit(sign_off);   // register the sign_off() function
    puts("Enter an integer");
    if (scanf("%i", &n) != 1) {
        puts("That's no integer!");
        atexit(too_bad);    // register the too_bad() function
        exit(EXIT_FAILURE);
    }
    return 0;
}

void sign_off(void) {
    puts("sign_off() was called");
}

void too_bad(void) {
    puts("too_bad() was called");
}