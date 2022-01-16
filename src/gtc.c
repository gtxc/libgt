/*
 * Created by gt on 1/16/22 - 5:37 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    puts("This is the C file");

    srandom(time(NULL));
    long x = random() % 100;
    printf("random number: %li\n", x);

    return 0;
}