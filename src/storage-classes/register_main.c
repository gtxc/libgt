/*
 * Created by gt on 10/19/21 - 11:15 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * used to define local variables that should be stored in register instead of RAM
 * that makes the use of register variables to be much faster than that of the
 * variables stored in the memory during the runtime of the program
 * should only be used for variables that require quick access
 * it is the compiler's choice to put in a register or not
 * lifetime of the register variable remains only when control is within in block
 * cannot obtain the address of the register variables using pointers (it does not have a memory address, it is a register)
 * but a pointer can be defined as register, pointer will be stored in a register
 * registers can be used only in a local block, cannot be defined as global
 *
 */

#include <stdio.h>

int main() {
    register int i = 0;
    int x = 5;
    register int *px = &x;

    for (; i < 5; ++i) {
        printf("i: %i\n", i);
    }
    printf("*px: %i\n", *px);
    return 0;
}