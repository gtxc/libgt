/*
 * Created by gt on 12/16/21 - 2:27 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    // make two processes which run the same program after this instruction
    fork();
    printf("GT\n");
    return 0;
}