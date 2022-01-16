/*
 * Created by gt on 12/9/21 - 3:55 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#define STACK_SIZE 5

struct s_node {
    int data[STACK_SIZE];
    int top;
};

_Bool initialize(struct s_node *stk) {
    if (stk) {
        stk->top = 0;
        return 1;
    }
    return 0;
}

_Bool push(struct s_node *stk, int data) {
    if (stk) {
        stk->data[stk->top] = data;
        ++stk->top;
    }
    return 0;
}

_Bool pop(struct s_node *stk) {
    if (stk) {
        --stk->top;
    }
    return 0;
}

void print_stack(struct s_node *stk) {
    if (stk) {
        for (int i = stk->top - 1; i >= 0; --i) {
            printf("%i\n", stk->data[i]);
        }
        return;
    }
    fprintf(stderr, "Stack is empty.\n");
}

int main() {
    struct s_node stk;
    initialize(&stk);
    push(&stk, 11);
    push(&stk, 22);
    push(&stk, 33);
    pop(&stk);
    print_stack(&stk);
    return 0;
}