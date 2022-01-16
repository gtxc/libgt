/*
 * Created by gt on 12/19/21 - 10:19 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

// order of applying mutex is important, potential for deadlock

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t lock1, lock2;

void *resource1() {
    pthread_mutex_lock(&lock1);
    puts("job started in resource1..");
    sleep(2);
    puts("trying to get resource2..");
    pthread_mutex_lock(&lock2);
    puts("acquired resource2");
    pthread_mutex_unlock(&lock2);
    puts("job finished in resource1..");
    pthread_mutex_unlock(&lock1);
    pthread_exit(NULL);
}

// solution to deadlock
void *resource1_upd() {
    pthread_mutex_lock(&lock1);
    puts("job started in resource1..");
    sleep(2);
    puts("trying to get resource2..");
    while (pthread_mutex_trylock(&lock2)) {
        pthread_mutex_unlock(&lock1);
        sleep(2);   // to not exhaust the cpu
        pthread_mutex_lock(&lock1);
    }
    puts("acquired resource2");
    pthread_mutex_unlock(&lock2);
    // do critical stuff here
    sleep(2);
    pthread_mutex_unlock(&lock1);
    puts("job finished in resource1..");
    pthread_exit(NULL);
}

void *resource2() {
    pthread_mutex_lock(&lock2);
    puts("job started in resource2..");
    sleep(2);
    puts("trying to get resource1..");
    pthread_mutex_lock(&lock1);
    puts("acquired resource1");
    pthread_mutex_unlock(&lock1);
    puts("job finished in resource2..");
    pthread_mutex_unlock(&lock2);
    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&lock1, NULL);
    pthread_mutex_init(&lock2, NULL);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, resource1_upd, NULL);
    pthread_create(&t2, NULL, resource2, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}