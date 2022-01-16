/*
 * Created by gt on 12/16/21 - 12:57 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler_dividebyzero(int signum) {
    if (signum == SIGFPE) {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    printf("Received %i Signal\n", signum);
}

int main() {
    int result, v1, v2;

    void (*sig_handler_return)(int);
    sig_handler_return = signal(SIGFPE, handler_dividebyzero);

    if (sig_handler_return == SIG_ERR) {
        perror("Signal Error: ");
        return 1;
    }

    v1 = 121;
    v2 = 0;
    result = v1 / v2;
    printf("Result of divide by zero is %i\n", result);
    return 0;
}