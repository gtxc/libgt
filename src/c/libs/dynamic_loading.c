/*
 * Created by gt on 11/15/2021 - 11:59.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * linking static or dynamic creates a dependency
 *
 * static or dynamic loading use library when they need
 *
 * useful for implementing plugins or modules
 * permits waiting to load the plugin until it is needed
 *
 */

#include <stdio.h>
#include <dlfcn.h>
#include <stdlib.h>

int main() {
    void *handle = NULL;
    char *error = NULL;

    char *lib_path = "/home/gt/ws/c/libgt/cmake-build-debug/libstr_functions_d.so";
    handle = dlopen(lib_path, RTLD_LAZY);

    if (!handle) {
        fputs(dlerror(), stderr);
        exit(EXIT_FAILURE);
    }

    // clears the error code
    dlerror();

    unsigned long int (*dlsym_return)(char[]) = NULL;
    dlsym_return = dlsym(handle, "str_length");

    if ((error = dlerror()) != NULL) {
        fputs(error, stderr);
        exit(EXIT_FAILURE);
    }

    char *gt = "Gurkan";
    unsigned long int gt_length;
    gt_length = (*dlsym_return)(gt);

    printf("%s has length %li\n", gt, gt_length);

    dlclose(handle);

    return 0;
}