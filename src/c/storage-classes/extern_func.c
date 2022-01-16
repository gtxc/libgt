/*
 * Created by gt on 10/19/21 - 10:40 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

//extern int main_to_foo;   // since foo_to_main is just used inside function foo() we can define inside function foo
int foo_to_main = 140;

// cannot be accessible from other files because of static
static void foo2() {
    printf("Inside foo2()\n");
}

void foo() {
    extern int main_to_foo;   // can be defined as local variable also
    printf("main_to_foo: %i\n", ++main_to_foo);
    foo2();
}
