/*
 * Created by gt on 12/19/21 - 9:03 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *calls(void *ptr) {
    // using pthread_self() to get current thread id
    printf("in function \nthread id = %li\n", pthread_self());
    pthread_exit(NULL);
    return NULL;
}

int main() {
    pthread_t thread;
    pthread_create(&thread, NULL, calls, NULL);
    printf("in main\nthread id = %li\n", thread);
    pthread_join(thread, NULL);
    return 0;
}