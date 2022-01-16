/*
 * Created by gt on 12/19/21 - 9:58 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <pthread.h>

#define N_THREADS 10

pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;
int counter = 0;

void *thread_function(void *dummy_ptr) {
    printf("thread number %li\n", pthread_self());
    pthread_mutex_lock(&mutex1);
    ++counter;
    pthread_mutex_unlock(&mutex1);
    return NULL;
}

int main() {
    pthread_t thread_id[N_THREADS];
    int i, j;
    for (i = 0; i < N_THREADS; ++i) {
        pthread_create(&thread_id[i], NULL, thread_function, NULL);
    }
    for (j = 0; j < N_THREADS; ++j) {
        pthread_join(thread_id[j], NULL);
    }
    printf("final counter value: %i\n", counter);
    return 0;
}