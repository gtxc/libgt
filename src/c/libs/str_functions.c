/*
 * Created by gt on 11/19/21 - 1:24 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include "str_functions.h"

unsigned long int number_of_characters_in_string(char *str, char search_character) {
    if (!str) {
        puts("Fed string is NULL");
        exit(EXIT_FAILURE);
    }
    unsigned long int frequency = 0;
    while (*str++) {
        if (*str == search_character) {
            ++frequency;
        }
    }
    return frequency;
}

_Bool remove_non_alpha_characters(char *source) {
    if (!source) {
        puts("Fed source is NULL");
        return 0;
    }
    int j;
    for (int i = 0; source[i] != '\0'; ++i) {
        while (!((source[i] >= 'A' && source[i] <= 'Z') || (source[i] >= 'a' && source[i] <= 'z'))) {
            for (j = i; source[j] != '\0'; ++j) {
                source[j] = source[j + 1];
            }
            source[j] = '\0';
        }
    }
    return 1;
}

unsigned long int str_length(char *source) {
    if (!source) {
        puts("Fed source is NULL");
        exit(EXIT_FAILURE);
    }
    unsigned long length = 0;
    while (*source++) {
        ++length;
    }
    return length;
}

_Bool str_concat(char *str1, const char *str2) {
    if (!str1 || !str2) {
        puts("One of the fed strings is NULL, or both");
        return 0;
    }
    int i ,j;
    for (i = 0; str1[i] != '\0'; ++i);
    for (j = 0; str2[j] != '\0'; ++j) {
        str1[i + j] = str2[j];
    }
    str1[i + j] = '\0';
    return 1;
}

_Bool str_copy(const char *source, char *destination) {
    if (!source || !destination) {
        puts("One of the fed strings is NULL, or both");
        return 0;
    }
    int i;
    for (i = 0; source[i] != '\0'; ++i) {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return 1;
}

_Bool substring(const char *source, int from, int n, char *target) {
    if (!source || !target) {
        puts("One of the fed strings is NULL, or both");
        return 0;
    }
    int i, j;
    for (i = 0; source[i] != '\0'; ++i);
    if (from > i) {
        puts("Index out of bounds");
        return 0;
    }

    n = from + n > i - from ? i : n;

    for (j = 0; j < n; ++j) {
        target[j] = source[from + j];
    }
    target[j] = '\0';
    return 1;
}