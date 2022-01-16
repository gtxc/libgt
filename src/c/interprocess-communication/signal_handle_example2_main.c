/*
 * Created by gt on 12/16/21 - 1:27 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>

void signal_handler(int signal_value) {
    int response;
    char *s = malloc(sizeof *s * 5);
    char *p = malloc(sizeof *p * 5);
    printf("%s%i%s\n%s", "\nInterrupt signal(", signal_value, ") received.",
                  "Do you wish to continue (1 = yes or 2 = no)\n");
    fgets(s, 5, stdin);
    response = (int) strtol(s, &p, 10);
    while (response != 1 && response !=2) {
        printf("(1 = ues or 2 = no)? ");
        fgets(s, 5, stdin);
        response = (int) strtol(s, &p, 10);
    }
    if (response == 1) {
        signal(SIGINT, signal_handler);
    } else {
        exit(EXIT_SUCCESS);
    }
}

int main() {
    int x;
    signal(SIGINT, signal_handler);
    // to ignore for example SIG_INT, pass SIG_IGN to the signal function as handler
//    signal(SIGINT, SIG_IGN);
    srandom(clock());
    for (int i = 1; i <= 1000; ++i) {
        x = (int) (1 + random() % 50);
        if (x == 25) {
            raise(SIGINT);
        }
        printf("%4i", i);
        if (i % 10 == 0) {
            puts("");
        }
    }
    return 0;
}