/*
 * Created by gt on 10/25/21 - 12:14 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int main() {
    printf("Enter words, chars in separate lines to take count of words and chars\n");
    int ch;
    int word_count = 0, ch_count = 0;

    while ((ch = getchar()) != EOF) {
        if (ch == '\n' || ch == ' ') {
            ++word_count;
        } else {
            ++ch_count;
        }
    }

    printf("Total words:\t%i\n", word_count);
    printf("Total chars:\t%i\n", ch_count);

    return 0;
}

