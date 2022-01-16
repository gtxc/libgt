/*
 * Created by gt on 11/8/2021 - 14:17.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

char *reverse_string_rec(char *s);

int main() {
    size_t buf = 100;
    char *s = malloc(sizeof *s * buf);
    if (!s) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    char *rev = NULL;

    printf("Enter the string: ");
    getline(&s, &buf, stdin);
    printf("Original string: %s\n", s);
    rev = reverse_string_rec(s);
    printf("Reversed string: %s\n", rev);

    free(s);
    return 0;
}