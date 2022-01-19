#include <stdio.h>

int task3(int A) {
    int length_A = 0, bak_A = A;
    while (A) {
        A /= 10;
        ++length_A;
    }

    A = bak_A;
    int arr_A[length_A];
    for (int i = 0; i < length_A; ++i) {
        arr_A[length_A - 1 - i] = A % 10;
        A /= 10;
    }

    int arr_shuffled_A[length_A];
    for (int i = 0, j = 0; i < length_A/2; ++i, j+=2) {
        arr_shuffled_A[j] = arr_A[i];
        arr_shuffled_A[j+1] = arr_A[length_A - 1 - i];
    }

    if (length_A % 2) arr_shuffled_A[length_A - 1] = arr_A[length_A / 2];

    int result = 0, multiplier = 1;
    for (int i = 0; i < length_A; ++i) {
        result += arr_shuffled_A[length_A - 1 - i] * multiplier;
        multiplier *= 10;
    }
    return result;
}

int main() {
    int shuffled = task3(1234567);
    printf("\nShuffled version passwd: %i\n", shuffled);
    return 0;
}