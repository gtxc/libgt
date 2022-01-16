/*
 * Created by gt on 11/10/21 - 11:55 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

//#pragma GCC poison printf
#pragma GCC warning "GT_warning"
// with gcc error code is not compiled
//#pragma GCC error "GT_error"
#pragma message "GT_message"
// this error is informative, code is compiled
#error *** This is the error***

#define JUST_CHECKING
#define LIMIT 4

#ifndef SIZE
    #define SIZE 10
#endif

int main() {
    int total = 0;
    for (int i = 1; i <= LIMIT; ++i) {
        total += 2 * i * i + 1;


        #ifdef JUST_CHECKING
            printf("i=%i, running total = %i\n", i, total);
        #endif
    }
    printf("Grand total = %i\n", total);
    #undef JUST_CHECKING

    #if SIZE == 10 && LIMIT && GG
        printf("size = %i\n", SIZE);
    #endif

    return 0;
}