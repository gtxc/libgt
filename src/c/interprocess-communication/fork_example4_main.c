/*
 * Created by gt on 12/17/21 - 4:35 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <unistd.h>

int main() {
    // creating first child
    int n1 = fork();
    // creating second child. First child also executes this line and creates a grandchild
    int n2 = fork();
    if (n1 > 0 && n2 > 0) {
        puts("parent");
        printf("%i %i \n", n1, n2);
        printf("\tmy id is %i \n", getpid());
        printf("\tmy parent id is %i \n", getppid());
    } else if (n1 == 0 && n2 > 0) {
        puts("first child");
        printf("%i %i \n", n1, n2);
        printf("\tmy id is %i \n", getpid());
        printf("\tmy parent id is %i \n", getppid());
    } else if (n1 > 0 && n2 == 0) {
        puts("second child");
        printf("%i %i \n", n1, n2);
        printf("\tmy id is %i \n", getpid());
        printf("\tmy parent id is %i \n", getppid());
    } else {
        puts("third child");
        printf("%i %i \n", n1, n2);
        printf("\tmy id is %i \n", getpid());
        printf("\tmy parent id is %i \n", getppid());
    }
    return 0;
}