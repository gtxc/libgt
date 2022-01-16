/*
 * Created by gt on 11/17/21 - 3:03 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

char *reverse_string_rec(char *s) {
    static char rev[100];
    static int count = 0;
    if (*s) {
        reverse_string_rec(s + 1);
        if (*s != '\n')
            rev[count++] = *s;
    }

    return rev;
}