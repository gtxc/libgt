/*
 * Created by gt on 10/23/21 - 1:29 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * sprint   : string print formatted sprintf(string, "%i %c %f", value, c, fit)
 *            returns number of chars stored in string not including, unsafe because it
 *            does not check the length of the destination buffer
 * fprintf  : performs the same operations as sprintf but on a file
 * fscanf   : performs the same operations as scanf but ona file
 * sscanf   : reads formatted data from a string rather than stdin
 * fflush   : cleans a file or buffer, causes any unwritten data in the output buffer
 *            to be sent to the output file
 *
 */

#include <stdio.h>
#include <stdlib.h>

int main() {

    char string[100];
    sprintf(string, "gt, this is the number %i", 17);
    puts(string);

    fprintf(stderr, "GTGTGTGTGT\n");

    FILE *fp;
    if (fopen("../src/data", "r") == NULL) {
        fprintf(stderr, "Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
