/*
 * Created by gt on 12/19/21 - 8:10 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include <pthread.h>

struct thread_data {
    int thread_id;
    int sum;
    char *message;
};

void *print_foo(void *thread_arg) {
    struct thread_data *my_data;
    int taskid = 0, sum = 0;
    char msg[255];
    my_data = (struct thread_data *) thread_arg;
    taskid = my_data->thread_id;
    sum = my_data->sum;
    strcpy(msg, my_data->message);
    printf("taskid = %i, sum = %i, message = %s\n", taskid, sum, msg);
}

int main() {
    pthread_t my_thread;
    struct thread_data my_thread_data;
    my_thread_data.message = malloc(sizeof (char) * 255);
    my_thread_data.thread_id = 10;
    my_thread_data.sum = 35;
    my_thread_data.message = "Foo";
    pthread_t my_id = pthread_create(&my_thread, NULL, print_foo, (void *) &my_thread_data);
    printf("my_id = %li\n", my_id);
    pthread_join(my_thread, NULL);
    pthread_exit(NULL);
    return 0;
}