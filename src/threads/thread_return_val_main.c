/*
 * Created by gt on 12/19/21 - 8:54 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <string.h>
#include <pthread.h>

void *return_foo(void *thread_arg) {
    // allocate a new string on the heap with "foo"
    char *foo = strdup("foo\n");
    return (void *) foo;
}

int main() {
    char *str;
    pthread_t thread;
    pthread_create(&thread, NULL, return_foo, NULL);
    pthread_join(thread, (void **) &str);
    printf("%s", str);
//    pthread_exit(NULL);
    return 0;
}