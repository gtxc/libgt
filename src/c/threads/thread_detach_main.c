/*
 * Created by gt on 12/19/21 - 9:13 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *threadfun(void *arg) {
    pthread_detach(pthread_self());
    sleep(1);
    puts("threadfun");
    pthread_exit(NULL);
}

int main() {
    pthread_t tid;
    int ret = pthread_create(&tid, NULL, threadfun, NULL);
    if (ret !=0) {
        perror("Thread creation error\n");
        exit(EXIT_FAILURE);
    }
    puts("After thread created in main");
    pthread_exit(NULL);
}