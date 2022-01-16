/*
 * Created by gt on 12/16/21 - 12:40 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main() {
    alarm(5);

    // need to catch SIGALARM or process terminates
    // signal(SIGALARM, alarm_handler);

    for (int i = 1; i < 10; ++i) {
        printf("%i\n", i);
        sleep(1);
    }


    return 0;
}