/*
 * Created by gt on 12/13/21 - 1:45 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int mypid, myppid;
    printf("Program to know PID and PPID's information\n");
    mypid = getpid();
    myppid = getppid();
    printf("My process ID is %i\n", mypid);
    printf("My parent process ID is %i\n", myppid);
    printf("Cross verification of pid's by executing process commands on shell:\n");
    system("ps -ef");
    return 0;
}