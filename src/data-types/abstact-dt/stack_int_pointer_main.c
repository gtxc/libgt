/*
 * Created by gt on 12/9/21 - 3:55 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

struct s_node_ {
    int data;
    struct s_node_ *down;
};

/** Edits the elements of the struct node.*/
_Bool edit_node(struct s_node_ *s_node_, int data, struct s_node_ *down) {
    if (s_node_) {
        s_node_->data = data;
        s_node_->down = down;
        return 1;
    }
    return 0;
}

/** Adds data on top of the stack.*/
_Bool push(struct s_node_ **top, int data) {
    if (!(*top)) {
        *top = malloc(sizeof **top);
        edit_node(*top, data, NULL);
        return 1;
    }
    if (*top) {
        struct s_node_ *down = malloc(sizeof *down);
        edit_node(down, (*top)->data, (*top)->down);
        edit_node(*top, data, down);
        return 1;
    }
    return 0;
}

/** Removes data on top of the stack.*/
int pop(struct s_node_ **top) {
    if (!(*top)) {
        fprintf(stdout, "Trying to pop from an empty stack.");
        exit(EXIT_FAILURE);
    }
    int popped = (*top)->data;
    struct s_node_ *tmp = *top;
    *top = (*top)->down;
    free(tmp);
    tmp = NULL;
    return popped;
}

/** Checks whether the stack is empty.*/
_Bool is_empty(struct s_node_ *top) {
    return top == NULL;
}

/** Looks the element on top without removing it.*/
int peek(struct s_node_ *top) {
    if (!top) {
        fprintf(stdout, "Trying to peek from an empty stack.");
        exit(EXIT_FAILURE);
    }
    return top->data;
}

/** Returns number of elements in the stack.*/
int stack_length(struct s_node_ *top) {
    if (top) {
        int length = 0;
        while (top) {
            ++length;
            top = top->down;
        }
        return length;
    }
    return 0;
}

/** Prints the stack content in separate lines.*/
void display_pancake(struct s_node_ *top) {
    if (top) {
        while (top) {
            printf("%i\n", top->data);
            top = top->down;
        }
        return;
    }
    fprintf(stderr, "Stack is empty.");
}

/** Frees all the elements of the stack.*/
_Bool empty_stack(struct s_node_ **top) {
    if (*top) {
        while (*top) {
            struct s_node_ *tmp = *top;
            *top = (*top)->down;
            free(tmp);
            tmp = NULL;
        }
        return 1;
    }
    return 0;
}

int main() {
    struct s_node_ *pancake = NULL;
    display_pancake(pancake);
    push(&pancake, 666);
    push(&pancake, 555);
    printf("popped: %i\n", pop(&pancake));
    push(&pancake, 444);
    empty_stack(&pancake);
    return 0;
}