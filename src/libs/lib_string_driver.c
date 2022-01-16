/*
 * Created by gt on 11/14/21 - 10:35 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <string.h>
#include "str_functions.h"

int main() {

    char str1[] = "Gu3r???k1an337 Tur5kar1slan";
    char str2[] = "E23li5f G6**irg5in";
    char *s = malloc(sizeof *s * 20);
    if (!s) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    strcpy(s, "s1*thing");
    char ss[10] = "";

    printf("str1: %s\n", str1);
    printf("str2: %s\n", str2);

    unsigned long int u_in_gt = number_of_characters_in_string(str1, 'u');
    printf("u's in gt: %li\n", u_in_gt);

    unsigned long int i_in_eg = number_of_characters_in_string(str2, 'i');
    printf("i's in eg: %li\n", i_in_eg);

    remove_non_alpha_characters(str1);
    remove_non_alpha_characters(str2);
    printf("after removing non-alpha chars str1: %s\n", str1);
    printf("after removing non-alpha chars str2: %s\n", str2);
    printf("%s\n", s);
    remove_non_alpha_characters(s);
    printf("%s\n", s);

    printf("length ofs str1 %li\n", str_length(str1));
    printf("length ofs str2 %li\n", str_length(str2));

    str_concat(str1, str2);
    printf("After strConcat str1: %s\n", str1);

    str_copy(s, str2);
    printf("After copy str2: %s\n", str2);

    substring(str1, 6, 14, ss);
    printf("After substring ss: %s\n", ss);

    free(s);

    return 0;
}
