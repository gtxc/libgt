/*
 * Created by gt on 12/19/21 - 7:48 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <pthread.h>

void *foo_func(void *ptr) {
    puts("foo");
    pthread_cancel(pthread_self());
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, foo_func, NULL);
    pthread_join(thread, NULL);
    return 0;
}