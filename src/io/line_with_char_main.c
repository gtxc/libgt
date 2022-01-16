/*
 * Created by gt on 10/25/21 - 10:23 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

#define BUF 256

_Bool has_ch(char ch, const char *line);

int main(int argc, char **argv) {
    FILE *fp = NULL;
    char ch;
    char line[BUF];

    if (argc != 3) {
        printf("Usage: %s character filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    ch = argv[1][0]; // because argv[0] is string, with a char and '\0'

    if (!(fp = fopen(argv[2], "r"))) {
        printf("Cannot open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, BUF, fp)) {
        if (has_ch(ch, line))
            fputs(line, stdout);
    }

    fclose(fp);
    return 0;
}