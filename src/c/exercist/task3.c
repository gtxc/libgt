/*
    In an even word, each letter occurs an even number of times.

    Write a function solution that, given a string S consisting of N characters, return the
    minimum number of letters that must be deleted to obtain an even word.

    Examples:

    1. Given S = "acbcbba", the function should return 1 (one letter b must be deleted).
    2. Given S = "axxaxa", the function should return 2 (one letter a and one letter x must be deleted).
    3. Given S = "aaaa", the function should return 0 (there is no need to delete any letters).

    Write an efficient algorithm for the following assumptions:

        - N is an integer within the range [0...200,000];
        - string S consists only of lowercase letters (a-z).
 */

#include <stdio.h>
#include <stdlib.h>

int solution(char *S) {
    int count = 0, ascii[256] = {0};
    while (*S) {
        ++ascii[*S];
        ++S;
    }
    for (int i = 0; i < 256; ++i) {
        if (ascii[i] % 2) {
            ++count;
        }
    }
    return count;
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
            long N = bytes_read - 4;
            char S[N];

            for (int i = 0, j = 0; i < bytes_read; ++i) {
                if (string[i] != '(' && string[i] != ')' && string[i] != '"' && string[i] != '\n') {
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