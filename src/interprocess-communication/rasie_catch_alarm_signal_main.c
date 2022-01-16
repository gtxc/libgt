/*
 * Created by gt on 12/17/21 - 2:23 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

/**/
//#define MAX_STR_LENGTH 10
//
//void alarm_handler() {
//    printf("\n\tNot answered within 3 seconds.\n");
//    raise(SIGINT);
//}
//
//void end_game_handler() {
//    printf("\n\tTerminating the game, thank you.\n");
//    exit(EXIT_SUCCESS);
//}
//
//int main() {
//    srandom(clock());
//    char *s = malloc(sizeof *s * MAX_STR_LENGTH);
//    long int answer;
//    int score = 0;
//    errno
//    while (1) {
//        signal(SIGALRM, alarm_handler);
//        signal(SIGINT, end_game_handler);
//        int num1 = random() % 10;
//        int num2 = random() % 10;
//        alarm(3);
//        printf("\t%i * %i = ", num1, num2);
//        fgets(s, MAX_STR_LENGTH, stdin);
//        answer = strtol(s, NULL, 10);
//        if (answer == num1 * num2) {
//            printf("\t\t \033[A score: %i\n", ++score);
//            continue;
//        } else {
//            printf("\t\t \033[A wrong!\n");
//        }
//    }
//    return 0;
//}
/**/


// sigaction version

/**/
int _score = 0;

void end_game() {
    printf("\nFinal score: %i\n", _score);
    exit(EXIT_SUCCESS);
}

int catch_signal(int sig, void (*handler)(int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;
    return sigaction(sig, &action, NULL);
}

void times_up() {
    puts("\nTIME's UP!");
    raise(SIGINT);
}

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(EXIT_FAILURE);
}

int main() {
    srandom(time(0));
    // start signal handling
    void (*sigHandlerAlarm)(int);
    void (*sigHandlerInterrupt)(int);
    sigHandlerAlarm = catch_signal(SIGALRM, times_up);
    sigHandlerInterrupt = catch_signal(SIGINT, end_game);
    if (sigHandlerAlarm == SIG_ERR || sigHandlerInterrupt == SIG_ERR) {
        error("Signal error!");
    }
    // end signal handling
    while (1) {
        int a = (int) random() % 11;
        int b = (int) random() % 11;
        char txt[4];
        alarm(5);
        printf("\nWhat is %i times %i: ", a, b);
        fgets(txt, 4, stdin);
        int answer = (int) strtol(txt, NULL, 10);
        if (answer == a * b) {
            ++_score;
        } else {
            printf("\nWrong! Score: %i\n", _score);
        }
    }
    return 0;
}
/* */