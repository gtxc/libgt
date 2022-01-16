/*
 * Created by gt on 10/21/21 - 1:11 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

#define bsize 100

void error_function(const char *buffer, int no_conversions) {
    fprintf(stderr, "An error occurred. You entered:\n%s\n", buffer);
    fprintf(stderr, "%d successful conversions", no_conversions);
    exit(EXIT_FAILURE);
}

int main() {
    char c, buffer[bsize];
    int x, y;
    float f, g;
    int r;

    printf("Enter two integers: ");
    fflush(stdout); // Make sure that the printf is executed before reading
    if (!fgets(buffer, bsize, stdin))
        error_function(buffer, 0);
    if ((r = sscanf(buffer, "%d%d", &x, &y)) != 2)
        error_function(buffer, r);

// Unless the input buffer was to small we can be sure that stdin is empty
// when we come here.
    printf("Enter two floats: ");
    fflush(stdout);
    if (!fgets(buffer, bsize, stdin))
        error_function(buffer, 0);
    if ((r = sscanf(buffer, "%f%f", &f, &g)) != 2)
        error_function(buffer, r);

// Reading single characters can be especially tricky if the input buffer
// is not emptied before. But since we're using fgets, we're safe.
    printf("Enter a char: ");
    fflush(stdout);
    if (!fgets(buffer, bsize, stdin))
        error_function(buffer, 0);
    if ((r = sscanf(buffer, "%c", &c)) != 1)
        error_function(buffer, r);

    printf("You entered %d %d %f %c\n", x, y, f, c);

    return 0;
}