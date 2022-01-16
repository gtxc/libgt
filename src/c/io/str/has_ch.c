/*
 * Created by gt on 11/17/21 - 2:53 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

/**
 * returns true for the lines have giving character
 */

#include <stdio.h>
#include <stdlib.h>

_Bool has_ch(char ch, const char *line) {
    if (!line) {
        puts("Fed line is NULL");
        exit(EXIT_FAILURE);
    }
    while (*line)
        if (ch == *line++)
            return 1;

    return 0;
}