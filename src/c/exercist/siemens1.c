/*
 * Created by gt on 1/30/22 - 8:21 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * https://app.codility.com/c/feedback/KC463W-V56/
 *
 * A string is called balanced when every letter occurring in the string, appears both in
 * upper and lowercase. For example, the string "CATattac" is balanced ('a', 'c' and 't'
 * occur int both cases), but "Madam" is not ('d' and 'a' appear only in lowercase). Note
 * that the number of occurrences does not matter.
 *
 * Write a function:
 *
 *      int solution(char *S);
 *
 * that, given a string S of length N, returns the length of the shortest balanced fragment
 * of S. if S does not contain any balanced fragments, the function should return -1.
 *
 * Examples:
 *
 *  1. Given S = "azABaabza", the function should return 5. The shortest balanced fragment of
 *     S is "ABaab".
 *
 *  2. Given S = "AcZCbaBz", the function should return 8. The shortest balanced fragment is
 *     the whole string.
 *
 *  3. Given S = "abcdefghijklmnopqrstuvwxvz", the function should return -1.
 *
 * Assume that:
 *
 *      N is an integer within the range [1..200];
 *      string S consists only of letters ('a'-'z' and/or 'A'-'Z').
 *
 * In your solution, focus on correctness. The performance of your solution will not be the focus
 * of the assessment.
 *
 *
 */

#include <stdio.h>
#include <string.h>

int solution(char *S) {
    int fragment = 1;
    int length_S = (int) strlen(S);
    for (int i = 1; i < length_S; ++i) {
    int balance = (int) S[i-1];
        for (int j = i; j < length_S; ++j) {
            balance ^= S[j];
            ++fragment;
            if (balance == 0) {
                return fragment;
            }
        }
        fragment = 1;
    }
    return -1;
}

int main() {
    char *S = "AcZCbaBz";
    printf("%i\n", solution(S));
    return 0;



}
