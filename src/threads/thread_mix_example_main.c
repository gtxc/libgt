/*
 * Created by gt on 12/19/21 - 11:41 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#define N_THREADS 10

int counter = 0;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t evens_done = PTHREAD_COND_INITIALIZER;
int number_evens_finished = 0;

void *foo(void *data) {
    int *msg = (int*) data;
    pthread_mutex_lock(&lock);
    if (*msg % 2 == 0) {
        ++number_evens_finished;
    } else {
        pthread_cond_wait(&evens_done, &lock);
    }
    ++counter;
    printf("thread id: %li, message = %i, mdfd counter = %i\n", pthread_self(), *msg, counter);
    printf("thread id: %li, message = %i, read counter = %i\n", pthread_self(), *msg, counter);
    puts("");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    pthread_t threads[N_THREADS];
    int values[N_THREADS];
    for (int i = 0; i < N_THREADS; ++i) {
        values[i] = i;
        pthread_create(&threads[i], NULL, foo, &values[i]);
    }
//    sleep(1);   // wait for the all threads are created
    while (1) {
        if (number_evens_finished == N_THREADS / 2) {
            pthread_cond_broadcast(&evens_done);
            break;
        }
    }
    for (int i = 0; i < N_THREADS; ++i) {
        pthread_join(threads[i], NULL);
        pthread_exit(&threads[i]);
    }
    return 0;
}