/*
 * Created by gt on 10/23/21 - 1:29 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * STDIN:
 *  gets     : reads a line from stdin into a buffer until terminating new line or EOF is found
 *             take one argument, a pointer to an array of chars where the string is stored
 *             returns str on success, and NULL on error or when end of file occurs
 *             no check for buffer overflow
 *             REMOVED FROM C11 (deprecated), never use it
 *  fgets    : reads a line from stdin, has similar behavior to gets
 *             accepts two additional arguments, the number of chars to read, and input stream
 *             only use fgets if it is certain the data read cannot contain a null char, otherwise use getline
 *  getline  : the latest function for reading a string of text, a new C library function
 *             having appeared around 2010 or so
 *             preferred method for reading lines of text from a stream (including stdin)
 *             the other standard functions gets, fgets, and scanf are too unreliable
 *             reads entire line from a stream, up to and including the next newline character
 *             and takes three arguments
 *
 * STDOUT:
 *  puts     : writes a line to the output screen
 *             the most convenient function for printing a simple message on standard output
 *             automatically appends a newline
 *  fputs    : writes a specified line to a file, does not add a newline character to the end of the string
 *
 */

#include <stdio.h>
#include <string.h>

int main() {
    char buf[255];
    unsigned char ch = '\0';
    char *p = NULL;
    fputs("Gurkan\n", stdout);
    puts("Enter anything:");
    if (fgets(buf, sizeof buf, stdin)) {
        p = strchr(buf, '\n');
        if (p)
            *p = '\0';
        else
            while (((ch = getchar()) != '\n') && !feof(stdin) && !ferror(stdin));
    } else {
        /* fgets failed, handle error */
    }
    puts("Entered:");
    puts(buf);

    return 0;
}