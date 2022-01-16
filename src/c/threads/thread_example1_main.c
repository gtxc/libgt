/*
 * Created by gt on 12/19/21 - 7:48 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <pthread.h>

void *foo() {
    puts("foo");
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t thread;
    pthread_create(&thread, NULL, foo, NULL);
    // if one of the below is not presented in the main, the thread may not be run
    // because main is not wait for the thread, when it returns all processes die
    pthread_join(thread, NULL);
//    pthread_exit(NULL);
    return 0;
}