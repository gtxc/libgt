/*
 * Created by gt on 11/18/21 - 10:20 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

/**
 * concatenates two string, returns char *
 */

#include <stdio.h>
#include <stdlib.h>

char *str_concat(const char *str1, const char *str2) {
    if (!str1 || !str2) {
        puts("One of the fed strings is NULL, or both");
        exit(EXIT_FAILURE);
    }
    unsigned long int i, j;
    for (i = 0; str1[i] != '\0'; ++i);
    for (j = 0; str2[j] != '\0'; ++j);

    char *result = malloc( sizeof *result * i * j);
    if (!result) {
        puts("Cannot allocate memeory");
        exit(EXIT_FAILURE);
    }

    for (unsigned long int k = 0; k < i; ++k) {
        result[k] = str1[k];
    }
    for (unsigned long int k = 0; k < j; ++k) {
        result[k + i] = str2[k];
    }
    result[i + j] = '\0';
    return result;
}