/*
 * Created by gt on 12/16/21 - 12:29 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <signal.h>

int main() {
    puts("Testing SIGSTOP");
    raise(SIGSTOP);
    // in bash after executing the program, run ps to show the pid of this and may continue it
    puts("I am back");
    return 0;
}
