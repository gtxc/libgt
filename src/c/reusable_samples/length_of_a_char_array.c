/*
 * Created by gt on 1/20/22 - 12:16 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>

int length_of_a_char_array(char *s) {
    int length = 0;
    while (*s++) ++length;
    return length;
}

int main() {
    printf("length of the char array: %i\n", length_of_a_char_array("12345"));
    return 0;
}