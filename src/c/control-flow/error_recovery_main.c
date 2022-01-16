/*
 * Created by gt on 10/22/21 - 11:08 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <setjmp.h>

jmp_buf buf;

void error_recovery() {
    printf("Detected an unrecoverable error.\n");
    longjmp(buf, -1);
}

int main() {
    while (1) {
        int val = setjmp(buf);
        printf("setjump(buf) = %i\n", val);
        if (val == -1) {
            printf("Back in main. %i\n", val);
            break;
        }
        else
            error_recovery();
    }
    return 0;
}