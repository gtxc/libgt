/*
 * Created by gt on 10/23/21 - 1:01 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * STDIN:
 *  getc     : reads from any input file (stdin is also a file).
 *  getchar  : reads only from stdin, requires no argument(s).
 *  fgetc    : reads a character from a file, moves the character pointer position to the next
 *             like getc, runs more slowly than getc, but takes less space per invocation.
 *  ungetc   : takes (int ch, FILE *stream), useful for unknown number of character inputs
 *
 * STDOUT:
 *  putc     : writes a single character to a file or stdout
 *  putchar  : writes only to stdout, requires no argument(s).
 *  fputc    : writes character into a file
 *
 */

#include <stdio.h>
#include <ctype.h>

int main() {
    unsigned char ch; // causes while loop infinite because ch cannot be -1 (EOF)
    ch = getc(stdin);
    printf("getc(stdin):  %c\n", ch);

    printf("Prints after white space(s).\n");
    while (isspace(ch = getchar()));

    ungetc(ch, stdin); // puts back the read character to the stream
    printf("getchar(): %c\n", getchar());

//    printf("Prints the input character(s).\node_");
//    while (putc(ch = getchar(), stdout));

    // --> below program can be used as cat a file to cli by taking program argument
//    while ((ch = getchar()) != EOF)
//        putchar(ch);
    // <--

    ungetc(ch, stdin);
    printf("End of program\n");

    // ungetc makes sense example
    // taking input till get 1 at the input
    // reads characters from the stdin and show them on stdout until encounters '1'
    while ((ch = getchar()) != '1')
        putchar(ch);
    // ungetc() return '1' previously read back to stdin
    ungetc(ch, stdin);
    // getchar() attempts to read next character from stdin and reads character '1' returned,
    // back to the stdin by ungetc()
    ch = getchar();
    // putchar() displays character
    putchar(ch);


    return 0;
}