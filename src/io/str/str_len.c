/*
 * Created by gt on 11/18/21 - 10:17 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

/**
 * returns length of the given string
 * ignores null terminator ('\0')
 */

#include <stdio.h>
#include <stdlib.h>

unsigned long int str_len(const char *s) {
    if (!s) {
        puts("Fed string is NULL");
        exit(EXIT_FAILURE);
    }
    unsigned long int length_s = 0;
    while (*s++) {
        ++length_s;
    }
    return length_s;
}