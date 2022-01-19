#include <stdio.h>
#include <stdlib.h>

struct Results {
    int *A;
    int N;
};

struct Results cyclicRotation(const int A[], int N, int K) {
    struct Results r;
    int *tmp = malloc(sizeof *tmp * N);
    if (!tmp) {
        puts("Cannot allocate memory");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < N; ++i) {
        tmp[(i + K) % N] = A[i];
    }

    r.A = tmp;
    r.N = N;

    return r;
}

int main() {
    int array[] = {1,2,3,4,5};
    int array_size;
    array_size = sizeof array / sizeof array[0];
    struct Results r;
    r = cyclicRotation(array, array_size, 3);
    for (int i = 0; i < array_size; ++i) {
        printf("r.A[%i] = %i\n", i, r.A[i]);
    }

    free(r.A);
    return 0;
}