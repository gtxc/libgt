/*
 * Created by gt on 1/30/22 - 8:21 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * https://app.codility.com/c/feedback/KC463W-V56/
 *
 * Write a function solution that, given a string S of length N, returns any palindrome which
 * can be obtained by replacing all of the question marks in S by lowercase letters ('a'-'z').
 * If no palindrome can be obtained, the function should return the string "NO".
 *
 * A palindrome is a string that reads the same both forwards and backwards. Some examples of
 * palindrome are: "kayak", "radar", "mom".
 *
 * Examples:
 *
 *  1. Given S = "?ab??a", the function should return "aabbaa".
 *  2. Given S = "bab??a", the function should return "NO".
 *  3. Given S = "?a?", the function may return "aaa". It may also return "zaz", among other
 *  possible answers.
 *
 * Assume that:
 *
 *      N is an integer within the range [1..1,000];
 *      string S consists only of lowercases letters ('a'-'z') or '?'.
 *
 * In your solution, focus on correctness. The performance of your solution will not be the
 * focus of the assessment.
 *
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char * solution(char *S) {
    int length_S = (int) strlen(S);
    char *tmp = S;
    char *rev = malloc(sizeof *rev * length_S);

    for (int i = 0; i < length_S; ++i) {
        rev[length_S - 1 - i] = tmp[i];
        if (rev[length_S - 1 - i] == '?') {
            rev[length_S - 1 - i] = tmp[length_S - 1 - i];
        }
        if (rev[length_S - 1 - i] == '?'){
            rev[length_S - 1 - i] = 'a';
        }
    }
    char *revrev = malloc(sizeof *revrev * length_S);
    for (int i = 0; i < length_S; ++i) {
        revrev[length_S - 1 - i] = rev[i];
    }
    printf("%s\n", rev);
    printf("%s\n", revrev);
    char *result = malloc(sizeof *result * length_S);
    strcpy(result, rev);
    if (strcmp(rev, revrev) != 0) {
        strcpy(result, "NO");
    }
    free(rev);
    free(revrev);
    rev = NULL;
    revrev = NULL;
    printf("%i\n", length_S);
    printf("%s\n", result);

    return result;
}

int main() {
//    char *S = "?ab??a";
    char *S = "?a?";
    printf("result: %s\n", solution(S));
    return 0;
}
