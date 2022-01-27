#include <stdio.h>

int oddOccurrencesInArray(const int A[], int N) {
    int result = 0;
    for (int i = 0; i < N; ++i) {
        result ^= A[i];
        printf("result = %i\n", result);
    }
    printf("\n 2 ^ 3 = %i\n", 0x3 ^ 3);
    return result;
}

int main() {
    int oddArray[] = {1,2,3,4,1,2,3};
    printf("odd occurrence: %i\n", oddOccurrencesInArray(oddArray, 7));
    return 0;
}