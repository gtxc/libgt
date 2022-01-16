/*
 * Created by gt on 12/16/21 - 1:31 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

// handler takes three parameters,
// because we are using sa_sigaction
static void hdl(int sig, siginfo_t *siginfo, void *context) {
    printf("Sending PID: %li, UID: %li\n", (long) siginfo->si_pid, (long) siginfo->si_uid);
}

int main(int argc, char **argv) {
    struct sigaction act;

    memset(&act, '\0', sizeof act);
    // use the sa_sigaction field because the handles has two additional parameters,
    // hdl contains a siginfo_t and a void pointer, see the function prototype
    act.sa_sigaction = &hdl;

    // the SA_SIGINFO flag tells sigaction() to use the sa_sigaction field, not sa handler
    act.sa_flags = SA_SIGINFO;

    // change the signal SIGTERM to SIGINT to check from console by pressing ctrl+c
    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction");
        return 1;
    }

    while (1) {
        sleep(3);
    }
    return 0;
}