/*
    You are given a string consisting of digits. Find the biggest two-digit value that is
    a consistent fragment of the given string.

    For example, two-digit consistent fragment of "50552" are ["50","05","55","52"],
    representing the numbers [50, 5, 55, 52]. The biggest value among them is 55.

    Write a function:

        int solution(char *S);

    that, given a string S consisting of digits, returns the maximum two-digit value that
    is a consistent fragment of S.

    Examples:

    1. Given S="50552", the function should return 55.
    2. Given S="10101", the function should return 10.
    3. Given S="88", the function should return 88.

    Assume that:

        - string S consists only of digits ['0'...'9'];
        - the number of digits of S is within the range [2...100];
        - S does not start with '0'.

    In your solution, focus on correctness. The performance of your solution will not be the
    focus of the assessment.
 */


#include <stdio.h>
#include <stdlib.h>

int solution(char *S) {
    int length_S = 0, result = 0;
    char *bak_S = S;
    while (*bak_S) {
        ++length_S;
        ++bak_S;
    }
    int twoDigitArray[length_S - 1];
    for (int i = 0; i < length_S - 1; ++i) {
        twoDigitArray[i] = (S[i] - 48) * 10 + S[i + 1] - 48;
    }
    for (int i = 0; i < length_S - 1; ++i) {
        if (result < twoDigitArray[i]) {
            result = twoDigitArray[i];
        }
    }
    return result;
}

int main(int argc, char **argv) {
    FILE *fp;
    char *filename;

    if (argc < 2) {
        printf("Missing filename\n");
        return 1;
    }

    filename = argv[1];
    fp = fopen(filename, "r");

    if (fp) {
        printf("filename : %s\n", filename);
        long bytes_read;
        int size = 1, testCounter = 1;
        char *string = malloc(sizeof *string);
        bytes_read = getline(&string, (size_t *) &size, fp);

        while (bytes_read != -1) {
            long N = bytes_read - 2;
            char S[N];

            for (int i = 0, j = 0; i < bytes_read; ++i) {
                if (string[i] != '(' && string[i] != ')' && string[i] != '\n') {
                    S[j] = string[i];
                    ++j;
                }
            }
            S[N - 1] = '\0';
            printf("Test #%i\n\tinput\t: %s\n\toutput\t: %i\n", testCounter, S, solution(S));
            bytes_read = getline(&string, (size_t *) &size, fp);
            ++testCounter;
        }
        free(string);
    } else {
        printf("Failed to open the file\n");
    }

    fclose(fp);
    return 0;
}