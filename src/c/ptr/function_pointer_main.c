/*
 * Created by gurk on 11/12/2021 - 13:39.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <malloc.h>

/// some random numbers
int array1[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int array2[] = {38, 27, 87, 63, 59, 223, 132, 1, 19, 7};

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
int mul(int a, int b) {return a * b;}
int div(int a, int b) {return a / b;}

/// Array of pointers to functions
int (*fpArr[])(int, int) = {&add, &sub, &mul, &div};

/// performs the given operation on elements of the arrays
int *performOp(int *a, int *b, unsigned int size, int (*f)(int, int)) {
    int *c = malloc(sizeof *c * size);
    for (int i = 0; i < size; ++i) {
        c[i] = (f)(a[i], b[i]);
    }

    return c;
}

/// display the elements of an array
void display(int *x, unsigned int size) {
    if (x == NULL) return;
    for (int i = 0; i < size; ++i) {
        printf("%i ", x[i]);
    }
    printf("\n");
}

/// main
int main() {
    int choice = 0;

    /// size of the array
    unsigned int size;

    int *result = NULL;

    /// set the size to minimum size of two arrays
    size = sizeof array1;

    if (sizeof array2 < size)
        size = sizeof array2;

    size = size / sizeof (int);

    while (choice != 5) {
        printf("\n\nWhich operation do you want to perform?\n");
        printf("1. Add\n");
        printf("2. Subtract\n");
        printf("3. Multiply\n");
        printf("4. Divide\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%i", &choice);

        if (choice == 5) break;
        if (choice < 1 || choice > 5) continue;

        int j = choice - 1;
        result = performOp(array1, array2, size, fpArr[j]);

        printf("\n\nThe results are ...\n");
        display(result, size);

        if (result != NULL)
            free(result);
    }

    return 0;
}