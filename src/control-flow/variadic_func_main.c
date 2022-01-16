/*
 * Created by gt on 11/26/21 - 7:59 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdarg.h>

void p(char a, int e, ...) {
    va_list args;
    va_start(args, e);
    int value = va_arg(args, int);
    while (value) {
        printf("value: %i\n", value);
        value = va_arg(args, int);
    }
    printf("value: %i\n", value);
    value = va_arg(args, int);
    printf("value: %i\n", value);
    value = va_arg(args, int);
    printf("value: %i\n", value);
    va_end(args);
}

int main() {
    p('g', 1, 2, 3, 4);
    printf("%i\n", '\0');
    return 0;
}