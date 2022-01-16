/*
 * Created by gt on 11/18/21 - 7:42 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

int str_cmp(const char *str1, const char *str2);

char **str_sort(char **str_list, size_t size) {
    if (!str_list) {
        puts("Fed string list is NULL");
        exit(EXIT_FAILURE);
    }
    char **sorted = malloc(sizeof *sorted * size);
    if (!sorted) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; ++i, ++str_list, ++sorted) {
        *sorted = *str_list;
    }
    sorted -= size;
    char *tmp;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (str_cmp(sorted[j], sorted[j + 1]) > 0) {
                tmp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = tmp;
            }
        }
    }
    return sorted;
}