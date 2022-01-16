/*
 * Created by gt on 11/23/21 - 11:56 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <malloc.h>

int main() {
    char *p1 = "Gurkan";
    char *p2 = NULL;
    p2 = strdup(p1);
    puts(p2);

    char source[] = "Gurkan";
    // 4 bytes of source are copied to a new memory
    // allocated dynamically and pointer to copied memory is returned.
    char *target = strndup(source, 4);
    puts(target);

    // must use free, since above funcs allocate memory dynamically
    free(p2);
    free(target);

    return 0;
}