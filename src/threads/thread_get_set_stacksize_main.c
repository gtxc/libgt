/*
 * Created by gt on 12/19/21 - 9:23 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_attr_t attr;

void *dowork(void *threadid) {
    long int tid;
    size_t mystacksize;
    tid = (long) threadid;
    pthread_attr_getstacksize(&attr, &mystacksize);
    printf("thread %li: stack size %li bytes\n", tid, mystacksize);
    pthread_exit(NULL);
}

int main() {
    pthread_t thread;
    size_t stacksize;
    pthread_t myid;
    long int t;
    pthread_attr_init(&attr);
    pthread_attr_getstacksize(&attr, &stacksize);
    printf("default stack size = %li\n", stacksize);
    stacksize = 9000000;
    printf("amount of stack needed per thread = %li\n", stacksize);
    pthread_attr_setdetachstate(&attr, stacksize);
    printf("creating thread with the stack size = %li bytes\n", stacksize);
    myid = pthread_create(&thread, &attr, dowork, (void *) t);
    if (myid) {
        printf("ERROR; return code from pthread_create() is %lud\n", myid);
        exit(-1);
    }
    pthread_exit(NULL);
    return 0;
}