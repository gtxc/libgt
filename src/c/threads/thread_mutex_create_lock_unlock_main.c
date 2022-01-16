/*
 * Created by gt on 12/19/21 - 9:48 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

pthread_mutex_t lock;

int j = 0;

void *do_process(void *a) {
    pthread_mutex_lock(&lock);
    int i = 0;
    ++j;

    while (i < 5) {
        printf("%i", j);
        sleep(1);
        ++i;
    }
    puts("...Done");
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main() {
    int err = 0;
    pthread_t t1, t2;
    if (pthread_mutex_init(&lock, NULL) != 0) {
        puts("Mutex initialization is failed.");
        return 1;
    }

    j = 0;

    pthread_create(&t1, NULL, do_process, NULL);
    pthread_create(&t2, NULL, do_process, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    return 0;
}
