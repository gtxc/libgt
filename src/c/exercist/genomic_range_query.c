/*
 * Created by gt on 1/30/22 - 2:16 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which
 * correspond to the types of successive nucleotides in the sequence. Each nucleotide has an
 * impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of
 * 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the
 * minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?
 *
 * The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N
 * characters. There are M queries, which are given in non-empty arrays P and Q, each consisting
 * of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of
 * nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).
 *
 * For example, consider string S = CAGCCTA and arrays P, Q such that:
 *
 *     P[0] = 2    Q[0] = 4
 *     P[1] = 5    Q[1] = 5
 *     P[2] = 0    Q[2] = 6
 * The answers to these M = 3 queries are as follows:
 *
 * The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose
 * impact factors are 3 and 2 respectively, so the answer is 2.
 * The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so
 * the answer is 4.
 * The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular
 * nucleotide A whose impact factor is 1, so the answer is 1.
 * Assume that the following declarations are given:
 *
 * struct Results {
 *   int * A;
 *   int M; // Length of the array
 * };
 *
 * Write a function:
 *
 * struct Results solution(char *S, int P[], int Q[], int M);
 *
 * that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q
 * consisting of M integers, returns an array consisting of M integers specifying the consecutive
 * answers to all queries.
 *
 * Result array should be returned as a structure Results.
 *
 * For example, given the string S = CAGCCTA and arrays P, Q such that:
 *
 *     P[0] = 2    Q[0] = 4
 *     P[1] = 5    Q[1] = 5
 *     P[2] = 0    Q[2] = 6
 * the function should return the values [2, 4, 1], as explained above.
 *
 * Write an efficient algorithm for the following assumptions:
 *
 * N is an integer within the range [1..100,000];
 * M is an integer within the range [1..50,000];
 * each element of arrays P and Q is an integer within the range [0..N - 1];
 * P[K] ≤ Q[K], where 0 ≤ K < M;
 * string S consists only of upper-case English letters A, C, G, T.
 *
 *
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

void print_int_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

struct Results {
    int *A;
    int M; // Length of the array
};

struct Results solution(char *S, int P[], int Q[], int M) {

    struct Results result;
    result.A = malloc(sizeof *result.A * M);
    result.M = M;
    int len_S = (int) strlen(S);
    int *counters[3];
    for (int i = 0; i < 3; ++i) {
        counters[i] = calloc(len_S+1, sizeof *counters[i]);
    }
    int a = 0;
    int c = 0;
    int g = 0;

    for (int i = 0; i < len_S; ++i) {
        if (S[i] == 'A') {
            ++a;
        } else if (S[i] == 'C') {
            ++c;
        } else if (S[i] == 'G') {
            ++g;
        }
        counters[0][i+1] = a;
        counters[1][i+1] = c;
        counters[2][i+1] = g;
    }
    print_int_array(counters[0], len_S+1);
    print_int_array(counters[1], len_S+1);
    print_int_array(counters[2], len_S+1);

    for (int i = 0; i < M; ++i) {
        int start_index = P[i];
        int end_index = Q[i]+1;
        int r = 4;
        for (int j = 0; j < 3; ++j) {
            if (counters[j][start_index] != counters[j][end_index]) {
                r = j+1;
                break;
            }
        }
        result.A[i] = r;
    }
    return result;
}

int main() {
    char *S = "C";
    int P[] = {0};
    int Q[] = {0};
    int size = sizeof P / sizeof P[0];
    struct Results results;
    results = solution(S, P, Q, size);
    print_int_array(results.A, results.M);
    return 0;
}
