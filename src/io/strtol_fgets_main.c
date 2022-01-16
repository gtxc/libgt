/*
 * Created by gt on 10/17/21 - 1:59 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
//#include <errno.h>
#include <limits.h>

enum { INPUT_SIZE = 30 };

int main () {
    char *ptr;
    long ret;
    char str[INPUT_SIZE];

    fgets(str, INPUT_SIZE, stdin);
    ret = strtol(str, &ptr, 10);

    if( ret == LONG_MAX || ret == LONG_MIN ) {
        perror("!! Problem is -> ");
    }
    else if (ret) {
        printf("The number is %ld\n", ret);
    }
    else {
        printf("No number found input is -> %s\n", ptr);
    }

    return(0);
}