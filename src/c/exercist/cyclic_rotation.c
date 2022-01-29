#include <stdio.h>
#include <stdlib.h>

struct Results {
    int *A;
    int N;
};

void print_int_array(int arr[], size_t size) {
    printf("[");
    for (unsigned long i = 0; i < size; ++i) {
        if (i == size - 1) printf("%i", arr[i]);
        else printf("%i, ", arr[i]);
    }
    printf("]\n");
}

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
    int A[] = {1,2,3,4,5};
    int size = sizeof A / sizeof A[0];
    struct Results result;
    result = cyclicRotation(A, size, 3);
    print_int_array(result.A, size);
    free(result.A);
    return 0;
}