/*
 * Created by gt on 11/18/21 - 11:04 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

/**
 * returns unsigned char * for the reversed string
 */

#include <stdio.h>
#include <stdlib.h>

char *str_rev(const char *s) {
    if (!s) {
        puts("Fed string is NULL");
        exit(EXIT_FAILURE);
    }
    unsigned long i;
    for (i = 0; s[i] != '\0'; ++i);
    char *rev = malloc(sizeof *rev * (i + 1));
    if (!rev) {
        puts("Cannot allocate memeory");
        exit(EXIT_FAILURE);
    }

    for (int j = 0; j < i; ++j) {
        rev[j] = s[i - 1 - j];
    }
    rev[i] = '\0';
    return rev;
}