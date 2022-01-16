/*
 * Created by gt on 11/19/21 - 1:43 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void change_pos(char *source) {
//    while (*source++);
    printf("in change_pos() source: %s\n", source);
    source[0] = 'G';
//    strcpy(source, "abcdefghi");
}

int main() {
    char *source = malloc(sizeof *source * 10);
    strcpy(source, "123456789");
    printf("in main() source: %s\n", source);
    change_pos(source);
    printf("in main() source: %s\n", source);
    free(source);
    return 0;
}