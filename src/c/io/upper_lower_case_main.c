/*
 * Created by gt on 10/25/21 - 9:14 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    unsigned char ch;
    printf("Enter a string to convert upper case:\n");
    while (stdin) {
         ch = fgetc(stdin);
         if (isupper(ch))
             fputc(ch, stdout);
         else
             fputc(toupper(ch), stdout);
    }
}