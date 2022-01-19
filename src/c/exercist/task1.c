/*
    You are given an implementation of a function:

        int solution(int A[], int N, int K);

    This function, given a non-empty array A of N integers (sorted in non-decreasing order)
    and integer K, checks whether A contains numbers 1,2,...,K (every number from 1 to K at
    least once) and no other numbers.

    For example, given the following array A, and K = 3:

        A[0] = 1
        A[1] = 1
        A[2] = 2
        A[3] = 3
        A[4] = 3

    The function should return 1.

    For the following array A, and K = 2:

        A[0] = 1
        A[1] = 1
        A[2] = 3

    the function should return 0.

    The attached code is still incorrect for some inputs. Despite the error(s), the code may
    produce a correct answer for the example test cases. The goal of the exercise is to find
    and fix the bug(s) in the implementation. You can modify at most two lines.

    Assume that:

        - N and K are integers within the range [1...300,000];
        - each element of array A is an integer within the range [0...1,000,000,000];
        - array A is sorted in non-decreasing order.

    In your solution, focus on correctness. The performance of your solution will not be the
    focus of the assessment.

    Given function:

        int solution(int A[], int N, int K) {
        int i;
        for (i = 0; i < N - 1; i++) {
            if (A[i] + 1 < A[i + 1])
                return 0;
        }
        if (A[0] != 1 && A[N - 1] != K)
            return 0;
        else
            return 1;
        }
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(const int A[], int N, int K) {
    int i;
    for (i = 0; i < N - 1; ++i) {
        if (A[i] + 1 < A[i + 1])
            break;
    }
    if (A[i] <  K)
        return 0;
    else
        return 1;
//    return A[i] < K ? 0 : 1;
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
            long N = bytes_read - 4 - ((bytes_read - 4)/2 + 1);
            int arr[N];
            int K = string[bytes_read - 3] - 48;

            for (int i = 0, j = 0; i < bytes_read - 3; ++i) {
                if (string[i] != '(' && string[i] != '[' && string[i] != ']' && string[i] != ')' && string[i] != ',' && string[i] != '\n') {
                    arr[j] = string[i] - 48;
                    ++j;
                }
            }
            printf("Test #%i\n\tinput\t: %s\toutput\t: %i\n", testCounter, string, solution(arr, (int) N, K));
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