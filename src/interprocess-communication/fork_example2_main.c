/*
 * Created by gt on 12/16/21 - 2:30 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#define MAX_COUNT 100
#define BUF_SIZE 100

int main() {
    pid_t pid;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();
    for (int i = 1; i <= MAX_COUNT; ++i) {
        sprintf(buf, "This line is from pid %i, value = %i\n", pid, i);
        write(1, buf, strlen(buf));
    }
    return 0;
}