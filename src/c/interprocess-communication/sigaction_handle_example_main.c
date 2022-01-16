/*
 * Created by gt on 12/16/21 - 1:11 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

// handler only takes one int as parameter,
// because we are using sa_handler
void termination_handler(int signum) {
    // before the termination doing some tidying up
    // unlink() function is not necessary, just an example
    struct tmp_file *p;
//    for (p = tmp_file_list; p; p = p->next) {
//        unlink(p->name);
//    }
}

int main() {
    struct sigaction new_action, old_action;

    // set up the structure to specify the new action
    new_action.sa_handler = termination_handler;
    sigemptyset(&new_action.sa_mask);
    new_action.sa_flags = 0;

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGINT, &new_action, NULL);
    }

    sigaction(SIGHUP, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGHUP, &new_action, NULL);
    }

    sigaction(SIGTERM, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGTERM, &new_action, NULL);
    }
}