#include <stdio.h>

int binarygap(int N) {
    int gap = 0;
    int max_gap = 0;
    int one_found = 0;
    while (N) {
        if (N & 1) {
            one_found = 1;
            max_gap = gap > max_gap ? gap : max_gap;
            gap = 0;
        } else {
            if (one_found) {
                ++gap;
            }
        }
        N >>= 1;
    }
    return max_gap;
}

int main() {
    printf("%i\n", binarygap(32));
    return 0;
}