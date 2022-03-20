#include <stdio.h>
#include <string.h>
#include "util.h"

#define NUMVALS 10
int main() {
    double vals[NUMVALS] = {1.2, 5, 78.3, 23.0, 0.004, 4.5, 23, 6.72, 17, 1};

    person me;
    strcpy(me.name, "Gurkan");
    me.age = 2022;

    printf("mean: %lf\n", getmean(vals, NUMVALS));
    print_person_info(&me);
    return 0;
}