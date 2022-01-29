/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *

    Write a function solution that, given an integer N, returns the maximum possible value
    obtainable by deleting one '5' digit from the decimal representation of N. It is
    guaranteed that N will contain at least one '5' digit.

    Examples:

    1. Given N = 15958, the function should return 1958.
    2. Given N = -5859, the function should return -589.
    3. Given N = -5000, the function should return 0. After deleting '5', the only digits
    in the number are zeros, so its value is 0.

    Assume that:

        - N is an integer within the range [-999,995...999,995];
        - N contains at least one '5' digit in its decimal representation;
        - N consist of at least two digits in its decimal representation.

    In your solution, focus on correctness. The performance of your solution will not be the
    focus of the assessment.
 */


#include <stdio.h>
#include <stdlib.h>

int solution(int N) {
    int length_N = 0, bak_N = N, isNeg = 0;

    if (bak_N < 0) {
        N *= -1;
        isNeg = 1;
    }

    while (bak_N) {
        bak_N /= 10;
        length_N++;
    }

    int arr_N[length_N];

    for (int i = 0; i < length_N; ++i) {
        arr_N[length_N - 1 - i] = N % 10;
        N /= 10;
    }

    int delFive = -1;

    if (isNeg) {
        for (int i = 0; i < length_N; ++i) {
            if (arr_N[i] == 5 && arr_N[i] > arr_N[i + 1]) {
                delFive = length_N - 1 - i;
                break;
            }
        }
    } else {
        for (int i = 0; i < length_N; ++i) {
            if (arr_N[i] == 5 && arr_N[i] < arr_N[i + 1]) {
                delFive = length_N - 1 - i;
                break;
            }
        }
    }

    if (delFive == -1) {
        for (int i = 0; i < length_N; ++i) {
            if (arr_N[length_N - 1 - i] == 5) {
                delFive = i;
                break;
            }
        }
    }

    int result = 0, multiplier = 1;

    for (int i = 0; i < length_N; ++i) {
        if (i != delFive) {
            result += arr_N[length_N - 1 - i] * multiplier;
            multiplier *= 10;
        }
    }

    if (isNeg) result *= -1;
    return result;
}

int main(int argc, char **argv) {
    FILE *fp;
    char *filename;

    if (argc < 2) {
        printf("Missing filename");
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if (fp) {
        printf("filename: %s\n", filename);
        long bytes_read;
        int size = 1, testCounter = 1;
        char *string = malloc(sizeof *string);
        bytes_read = getline(&string, (size_t *) &size, fp);

        while (bytes_read != -1) {
            int N = 0, multiplier = 1, isNeg = string[1] == '-';

            for (int i = 0, j = 0; i < bytes_read; ++i) {
                if (string[bytes_read - 1 - i] != '(' && string[bytes_read - 1 - i] != ')' && string[bytes_read - 1 - i] != '\n' && string[bytes_read - 1 - i] != '-') {
                    N += (string[bytes_read - 1 - i] - 48) * multiplier;
                    ++j;
                    multiplier *= 10;
                }
            }
            if (isNeg) N *= - 1;
            printf("Test #%i\n\tinput\t: %i\n\toutput\t: %i\n", testCounter, N, solution(N));
            bytes_read = getline(&string, (size_t *) &size, fp);
            ++testCounter;
        }
    } else {
        printf("Failed to open file\n");
    }

    fclose(fp);
    return 0;
}