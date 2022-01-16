/*
 * Created by gt on 10/19/21 - 10:40 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int main_to_foo = 15;
extern int foo_to_main;
extern void foo();
//extern void foo2();

int main() {
    ++main_to_foo;
    printf("foo_to_main: %i\n", ++foo_to_main);
    foo();
    return 0;
}