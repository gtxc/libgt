/*
 * Created by gt on 12/13/21 - 12:13 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>

struct q_node {
    int key;
    struct q_node *next;
};

struct queue {
    struct q_node *front, *rear;
};

struct q_node *new_node(int k) {
    struct q_node *tmp = malloc(sizeof *tmp);
    tmp->key = k;
    tmp->next = NULL;
    return tmp;
}

struct queue *create_queue() {
    struct queue *q = malloc(sizeof *q);
    q->front = q->rear = NULL;
    return q;
}

_Bool enqueue(struct queue *q, int k) {
    struct q_node *tmp = new_node(k);
    if (!q->rear) {
        q->front = q->rear = tmp;
        return 1;
    }
    if (q->rear) {
        q->rear->next = tmp;
        q->rear = tmp;
        return 1;
    }
    return 0;
}

struct q_node *dequeue(struct queue *q) {
    if (q->front) {
        struct q_node *tmp = q->front;
        q->front = q->front->next;
        if (!q->front) {
            q->rear = NULL;
        }
        return tmp;
    }
    return NULL;
}

_Bool is_empty() {

    return 0;
}

_Bool is_full() {

    return 0;
}

/** Dequeues from the queue without removing the element.*/
int peek() {

}

/** Enqueues from the queue without removing the element.*/
int poll() {

}

int main() {
    struct queue *q = create_queue();
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    struct q_node *n = dequeue(q);
    n = dequeue(q);
    if (n) {
        printf("Dequeued item: %i\n", n->key);
    }
    printf("q->front: %i\n", q->front->key);
    printf("q->rear: %i\n", q->rear->key);
    return 0;
}