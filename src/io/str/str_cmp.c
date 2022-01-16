/*
 * Created by gt on 11/18/21 - 10:51 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

/**
 * compares two strings
 * returns:
 *      -1 if the first non equal character in str1 is less than str2
 *      1 if the first non equal character in str1 is greater than str2
 *      0 if the strings are equal
 *      -1 or 1 with respect to length of the strings in the case of equality in compared parts
 */

#include <stdio.h>
#include <stdlib.h>

int str_cmp(const char *str1, const char *str2) {
    if (!str1 || !str2) {
        puts("One of the fed strings is NULL, or both");
        exit(EXIT_FAILURE);
    }
    unsigned long int i, j;
    for (i = 0; str1[i] != '\0'; ++i);
    for (j = 0; str2[j] != '\0'; ++j);
    unsigned long int iter = i < j ? i : j;
    for (unsigned long int k = 0; k < iter; ++k) {
        if (str1[k] < str2[k]) {
            return -1;
        } else if (str1[k] > str2[k]) {
            return 1;
        }
    }
    return i < j ? -1 : i > j ? 1 : 0;
}