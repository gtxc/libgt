/*
 * Created by gt on 12/13/21 - 2:29 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#define MAX 50

int queue_array[MAX];
int rear = -1;
int front = -1;

void enqueue(int item) {
    if (rear == MAX - 1) {
        fprintf(stderr, "Queue overflow.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    ++rear;
    queue_array[rear] = item;
}

void dequeue() {
    if (front == -1 || front > rear) {
        fprintf(stderr, "Queue underflow.\n");
        return;
    }
    printf("Dequeued element: %i\n", queue_array[front]);
    ++front;
}

void display() {
    if (front == -1) {
        fprintf(stderr, "Queue is empty.\n");
        return;
    }
    for (int i = front; i <= rear; ++i) {
        printf("%i ", queue_array[i]);
    }
    printf("\n");
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    display();
    return 0;
}
