/*
 * Created by gt on 10/12/21 - 10:26 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
//#include <sys/time.h> // platform dependent (linux)
#include <time.h>   // platform independent

enum { INPUT_SIZE = 30 };

void init_randomization(){
    time_t timer;
    struct tm *current_time;
    time(&timer);
    current_time = localtime(&timer);
    srandom((unsigned long int) current_time);
}

void guess_number() {
    char *str = malloc(sizeof *str * INPUT_SIZE);
    char *str_remains;
    long guess;

    long r_num = random() % 21;
    printf("Number to found: %li\n", r_num);
    printf("Guess the number between 0 - 20\n");
    while (1) {
        printf("Enter the number: ");
        fgets(str, INPUT_SIZE, stdin);
        guess = strtol(str, &str_remains, 10);
        if (guess == r_num) break;
        printf("%s\n", guess > r_num ? "high" : "low");
    }
    printf("congrats\n");
}

int main() {
    init_randomization();
    guess_number();
    return 0;
}