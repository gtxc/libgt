/*
 * Created by gt on 12/19/21 - 7:57 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *printf_message(void *ptr) {
    char *message = (char *) ptr;
    printf("%s \n", message);
}

int main() {
    pthread_t thread1, thread2;
    char *message1 = "Thread 1";
    char *message2 = "Thread 2";
    int iret1, iret2;

    /* create independent threads each of which will execute functions*/
    iret1 = pthread_create(&thread1, NULL, printf_message, (void*) message1);
    iret2 = pthread_create(&thread2, NULL, printf_message, (void*) message2);
    /* wait till threads are complete before main continues. Unless we
     * wait we rn the risk of executing an exit which will terminate
     * the process and all threads before the threads have completed*/
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    printf("Thread 1 return: %i\n", iret1);
    printf("Thread 2 return: %i\n", iret2);
    pthread_exit(NULL);
    exit(EXIT_SUCCESS);
}