/*
 * Created by gt on 11/24/21 - 12:30 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <time.h>
#include <math.h>
#include <ctype.h>

int main() {
    time_t calendar_start = time(NULL);             // inital calendar time
    clock_t cpu_start = clock();                        // initial processor time
    int count;                                          // count of number of loops

    const long long iterations = 1000000000LL;
    char answer = 'y';
    double x;

    printf("Initial clock time = %lli\nInitial calender time = %lli\n", (long long) cpu_start, (long long) calendar_start);

    while (tolower(answer) == 'y') {
        for (long long int i = 0LL; i < iterations; ++i) {
            x = sqrt(3.14159265);
        }
        printf("%lli square roots completed.\n", iterations * (++count));
        printf("Do you want to run some more (y or node_)? \node_");
        scanf("\n%c", &answer);
    }

    clock_t cpu_end = clock();                  // final cpu time
    time_t calender_end = time(NULL);       // final calendar time

    printf("Final clock time = %lli\nFinal calender time = %lli\n", (long long) cpu_end, (long long) calender_end);
    printf("CPU time for %lli iterations is %.2lf seconds\n", count * iterations, ((double) (cpu_end - cpu_start)) / CLOCKS_PER_SEC);
    printf("Elapsed calendar time to execute the program is %.2lf seconds\n", difftime(calender_end, calendar_start));

    long int gg = 10L;
    time_t *timer = &gg;
    time_t calendar = time(timer);
    printf("ctime: %s\n", ctime(&calendar));
    printf("timer %li\n", *timer);

    time_t cal = time(NULL);            // current calendar time
    struct tm *time_data = localtime(&cal);
    printf("tm: %i %i %i %i %i %i %i\n", time_data->tm_sec, time_data->tm_min, time_data->tm_hour, time_data->tm_mon, time_data->tm_year, time_data->tm_wday, time_data->tm_isdst);
    time_t t_ptr;
    time(&t_ptr);
    printf("asctime: %s\n", asctime(localtime(&t_ptr)));

    // time in seconds form 1 January 1970
    time_t n = time(NULL);
    printf("%li\n", n);

    return 0;
}