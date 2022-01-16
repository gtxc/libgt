/*
 * Created by gt on 11/12/2021 - 11:57.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <malloc.h>

void change_value(int **p) {
    int a = 2;
    *p = &a;
    printf("*p_ in change_value(): %i\n", **p);
}

void allocate_memeory(int **p) {
    *p = malloc(sizeof (int));
}

int main() {
    int *p = malloc(sizeof (int));
    printf("p_: %p_\n", p);
    *p = 5;
    free(p);
    printf("p_: %p_\n", p);
    change_value(&p);
    printf("*p_ in main(): %i\n", *p);
    printf("p_: %p_\n", p);

    int *ptr = NULL;
    printf("ptr: %p_\n", ptr);
    printf("&ptr: %p_\n", &ptr);
    allocate_memeory(&ptr);
    printf("ptr: %p_\n", ptr);
    printf("&ptr: %p_\n", &ptr);
    free(ptr);

    //function pointer
    void (*func_ptr)(int **p);
    func_ptr = allocate_memeory;
    printf("Address of the allocate_memeory(): %p_\n", func_ptr);



    return 0;
}