/*
 * Created by gt on 12/19/21 - 11:13 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t count_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t condition_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t condition_cond = PTHREAD_COND_INITIALIZER;

int count = 0;

#define COUNT_DONE 10
#define COUNT_HALT1 3
#define COUNT_HALT2 6

void *function_count1(void *a) {
    for (;;) {
        pthread_mutex_lock(&condition_mutex);
        while (count >= COUNT_HALT1 && count <= COUNT_HALT2) {
            pthread_cond_wait(&condition_cond, &condition_mutex);
        }
        pthread_mutex_unlock(&condition_mutex);
        pthread_mutex_lock(&count_mutex);
        ++count;
        printf("counter value function_count1: %i\n", count);
        pthread_mutex_unlock(&count_mutex);
        if (count >= COUNT_DONE) {
            return NULL;
        }
    }
}

void *function_count2(void *a) {
    for (;;) {
        pthread_mutex_lock(&condition_mutex);
        if (count < COUNT_HALT1 || count > COUNT_HALT2) {
            pthread_cond_signal(&condition_cond);
        }
        pthread_mutex_unlock(&condition_mutex);
        pthread_mutex_lock(&count_mutex);
        ++count;
        printf("counter value function_count2: %i\n", count);
        pthread_mutex_unlock(&count_mutex);
        if (count >= COUNT_DONE) {
            return NULL;
        }
    }
}

int main() {
    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, function_count1, NULL);
//    sleep(1);
    pthread_create(&thread2, NULL, function_count2, NULL);
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    return 0;
}