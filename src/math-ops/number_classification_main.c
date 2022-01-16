/*
 * Created by gt on 11/2/2021 - 13:29.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

_Bool is_odd(int n);
_Bool is_prime(int n);

int main() {
    FILE *fp;
    int n, s;
    char *string = malloc(sizeof *string * 20);
    char **p = malloc(sizeof *p * 20);

    fp = fopen("../input/number.txt", "r");
    if (fp  == NULL) {
        fprintf(stderr, "Cannot open file.\n");
        exit(EXIT_FAILURE);
    }

    do {
        s = fscanf(fp, "%s", string);
        n = (int) strtol(string, p, 10);

        if (s != -1) {
            if (is_prime(n))
                printf("Prime number found %i\n", n);
            else if (is_odd(n))
                printf("Odd number found %i\n", n);
            else
                printf("Even number found %i\n", n);
        }
    } while (s != -1);

    fclose(fp);
    fp = NULL;
    free(string);
    free(p);
}