/*
 * Created by gt on 1/30/22 - 8:21 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * https://app.codility.com/c/feedback/KC463W-V56/
 *
 * You are given a string S, consisting of N digits, that represents a number. You can change at
 * most one digit in the string to any other digit. How many different numbers divisible by 3 can
 * be obtained in this way?
 *
 * Write a function:
 *
 *      int solution(char *S);
 *
 * that, given a string S of length N, returns an integer specifying how many numbers divisible by
 * 3 can be obtained with at most one change of a digit.
 *
 * Examples:
 *
 * 1. Given S = "23", the function should return 7. All numbers divisible by 3 that can be obtained
 *    after at most one change are: "03", "21", "24", "27", "33", "63" and "93".
 *
 * 2. Given S = "0081", the function should return 11. All numbers divisible by 3 that can be obtained
 *    with at most one change are: "0021", "0051", "0081", "0084", "0087", "0381", "0681", "0981",
 *    "3081", "6081" and "9081".
 *
 * 3. Given S = "022", the function should return 9. All numbers divisible by 3 that can be obtained
 *    with at most one change are: "012", "021", "024", "027", "042", "072", "222", "522" and "822".
 *
 * Write an efficient algorithm for the following assumptions:
 *
 *      N is an integer within the range [1..100,000];
 *      string S consists only of digits (0-9).
 *
 */

#include <stdio.h>
#include <string.h>

void print_int_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

int solution(char *S) {
    int length_S = (int) strlen(S);
    int arr[length_S];

    for (int i = 0; i < length_S; ++i) {
        arr[i] = S[i] - 48;
    }
    int result = 0;
    int sum_arr = 0;

    for (int i = 0; i < length_S; ++i) {
        sum_arr += arr[i];
    }
    int sum_arr_bak = sum_arr;

    for (int i = 0; i < length_S; ++i) {
        sum_arr -= arr[i];
        for (int j = 0; j < 10; ++j) {
            if ((sum_arr + j) % 3 == 0) {
                ++result;
            }
        }
        sum_arr = sum_arr_bak;
    }
    return (sum_arr % 3 == 0) ? result - length_S + 1 : result;
}

int main() {
    printf("%i\n", solution("23"));
    printf("%i\n", solution("0081"));
    printf("%i\n", solution("022"));
    return 0;
}
