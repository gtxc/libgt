/*
 * Created by gt on 10/19/21 - 10:28 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

void foo(void) {
    static int count = 0;
    auto int local_var = 0; // auto is optional here, every local variable has an invisible auto in front of it
    printf("Automatic var = %i, static var = %i\n", local_var++, count++);
}

int main() {

    for (int i = 0; i < 5; ++i) {
        foo();
    }
    return 0;
}