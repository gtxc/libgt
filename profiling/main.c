/*
 * Created by gt on 10/21/21 - 4:32 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

struct packed_struct {
    int count;
    char c;
    unsigned int : 3; // unnamed bits, for padding
    unsigned int f1: 1;
    unsigned int f2: 1;
    unsigned int f3: 1;
    unsigned int type: 8;
    unsigned int index: 18;
};

int main() {

    struct packed_struct ps = {17, 'g', .f1 = 1,.f2 = 0,.f3 = 1,.type = 2, .index = 262143};

    printf("sizeof ps: %li\n", sizeof ps);

    int count = ps.count;
    char c = ps.c;
    unsigned int f1 = ps.f1;
    unsigned int f2 = ps.f2;
    unsigned int f3 = ps.f3;
    unsigned int type = ps.type;
    unsigned int index = ps.index;
    printf("count: %i\n", count);
    printf("c: %c\n", c);
    printf("f1: %u\n", f1);
    printf("f2: %u\n", f2);
    printf("f3: %u\n", f3);
    printf("type: %u\n", type);
    printf("index: %u\n", index);

    return 0;
}
