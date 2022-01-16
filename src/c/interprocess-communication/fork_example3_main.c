/*
 * Created by gt on 12/16/21 - 2:36 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 100

void child_process() {
    for (int i = 1; i <= MAX_COUNT ; ++i) {
        printf("    This line is from child, value = %i\n", i);
    }
    printf("    *** Child process is done ***\n");
}

void parent_process() {
    for (int i = 1; i <= MAX_COUNT ; ++i) {
        printf("    This line is from parent, value = %i\n", i);
    }
    printf("    *** Parent process is done ***\n");
}

int main() {
    pid_t  pid;
    pid = fork();
    if (pid == 0) {
        child_process();
    } else if (pid > 0) {
        parent_process();
    } else {
        printf("fork() failed!\n");
        return 1;
    }
    return 0;
}