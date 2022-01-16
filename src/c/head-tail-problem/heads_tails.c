/*
 * Created by gt on 11/30/21 - 1:05 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int min_flip(char *s) {
    int h_count = 0, t_count = 0;
    while (*s++) {
        if (*s == 'H') {
            ++h_count;
        } else {
            ++t_count;
        }
    }
    printf("h_count: %i\n", h_count);
    printf("t_count: %i\n", t_count);
    return t_count <= h_count ? t_count : h_count;
}

int digi(char *s) {
    char r = '\0';
    while (*s++) {
        r = r ^ *s;
        printf("r: %i\n", r);
    }
    return r;
}

int mini(char *s) {
    int length_s = 0, T_count = 0, H_count = 0;
    char *tmp = s;
    while (*tmp) {
        ++length_s;
        H_count += *tmp == 'H' ? 1 : 0;
        T_count += *tmp == 'T' ? 1 : 0;
        ++tmp;
    }

    if (H_count == length_s || T_count == length_s) {
        puts("Beautiful string (HH.. or TT..)");
    }

    tmp -= length_s;
    _Bool H_lead = *tmp == 'H' ? 1 : 0;
    int i, T_stream, sub_T_count;
    if (H_lead) {
        for (i = 1; i < length_s; ++i) {
            if (tmp[i] == 'T') {
                T_stream = 0;
                sub_T_count = length_s - i;
                for (int j = i; j < length_s; ++j) {
                    if (tmp[j] == 'T') {
                        ++T_stream;
                    }
                }
                if (T_stream == sub_T_count) {
                    puts("Beautiful string (H..T..)");
                    return 0;
                }
            }
        }
        if (i >= sub_T_count && sub_T_count > T_stream) {
            printf("min flip: %i\n", T_stream);
            return T_stream;
        }

    }
    return 0;
}

int mf(char *s) {
    int length_s = 0;
    while (*s++) {
        ++length_s;
    }
    s -= length_s + 1;
    int arr_t[length_s];
    int arr_h[length_s];
    int change = 0;
    for (int i = 0; i < length_s; ++i) {
        if (s[i] == 'T') {
            ++change;
        }
        arr_t[i] = change;
    }
    change = 0;
    for (int i = length_s - 1; i >= 0; --i) {
        if (s[i] == 'H') {
            ++change;
        }
        arr_h[i] = change;
    }
    printf("left  :");
    for (int i = 0; i < length_s; ++i) {
        printf("[%i]", arr_t[i]);
    }
    puts("");
    printf("right :");
    for (int i = 0; i < length_s; ++i) {
        printf("[%i]", arr_h[i]);
    }
    return 1;
}

unsigned long mnoff(char *s) {
    unsigned long length_s = 0, T_count = 0, H_count = 0;
    while (*s) {
        ++length_s;
        H_count += *s == 'H' ? 1 : 0;
        ++s;
    }
    s -= length_s;
    unsigned long min_flip = length_s - H_count;
    while (*s != '\0') {
        if (*s == 'H') {
            --H_count;
        } else {
            min_flip = min_flip < T_count + H_count ? min_flip : T_count + H_count;
            ++T_count;
        }
        ++s;
    }
    return min_flip;
}

int main() {
    printf("mf: %li\n", mnoff("HTHHTTT"));
    printf("mf: %li\n", mnoff("TTTTH"));
    printf("mf: %li\n", mnoff("HHHT"));
    printf("mf: %li\n", mnoff("HHHHHH"));
    printf("mf: %li\n", mnoff("HTHHHTHHHTT"));
    printf("mf: %li\n", mnoff("THHTTTHTTTHH"));
    printf("mf: %li\n", mnoff("TTTT"));
    puts("END");
    return 0;
}

