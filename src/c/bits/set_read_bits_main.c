/*
 * Created by gt on 10/21/21 - 10:36 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define bsize 20

long long int dec_to_bin(long int dec);

int main() {
    char *ptr = NULL;
    char *str = malloc(sizeof *str * bsize);
    if (!str) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    long int number, newNumber;
    long long int binNumber, binNewNumber;
    char bitPos;
    _Bool bitStatus;

    printf("Enter any number: ");
    fgets(str, bsize, stdin); // fgets(buffer, bufferSize, stdin)
    number = strtol(str, &ptr, 10);


    printf("Enter the nth bitPos to check and set (0 - 31): ");
    fgets(str, bsize, stdin);
    bitPos = (char) strtol(str, &ptr, 10);

    bitStatus = (_Bool) (number >> bitPos & 1);
    newNumber = number | 1 << bitPos;
    binNumber = dec_to_bin(number);
    binNewNumber = dec_to_bin(newNumber);

    printf("bitPos: \t%i\n", bitPos);
    printf("bitStatus: \t%i\n", bitStatus);
    printf("number: \t%li\tin binary: \t%lli\n", number, binNumber);
    printf("newNumber: \t%li\tin binary: \t%lli\n", newNumber, binNewNumber);

    free(str);
    str = NULL;
    ptr = NULL;

    return 0;
}