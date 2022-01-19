#include <stdio.h>

int binarygap(int N) {
    int zeroCount = 0, maxCount = 0;
    while (N) {
        if (N & 1) {
            maxCount = zeroCount > maxCount ? zeroCount : maxCount;
            zeroCount = 0;
        } else {
            ++zeroCount;
        }
        N >>= 1;
    }
    return maxCount;
}

int main() {
    printf("%i\n", binarygap(1234));
    return 0;
}