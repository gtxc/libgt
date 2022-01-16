/*
 * Created by gt on 10/18/21 - 12:45 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//one-time use struct (anonymous), there is no tag name
struct {
    int date;
    int month;
    int year;
} today, yesterday;

struct Family {
    char name[20];
    int age;
    char father[20];
    char mother[20];
};

bool siblings(struct Family member1, struct Family member2) {
    if (strcmp(member1.mother, member2.mother) == 0)
        return true;
    else
        return false;
}

// struct Family const *pmember : cannot change the values of the variables in the struct.
// struct Family *const pmember : cannot change the address of the struct pointer since function
// takes the copy of the struct pointer, it is pointless to use *const

bool siblings2(struct Family const *pmember1, struct Family const *pmember2) {
    printf("in siblings2(...), pmember1->age : %i\n", pmember1->age);
    struct Family gt = {.age = 17};
    pmember1 = &gt; // does not work
    printf("in siblings2(...), pmember1->age : %i\n", pmember1->age);
    if (!strcmp(pmember1->mother, pmember2->mother))
        return true;
    else
        return false;
}

int main() {
    struct Family member1 = {"gt", 30, "aragorn", "Arwen"};
    struct Family member2 = {"orc", 33, "aragorn", "arwen"};
    printf("siblings: %s\n", siblings(member1, member2) ? "true" : "false");

    struct Family *pmember1 = &member1;
    struct Family *pmember2 = &member2;
    printf("siblings2: %s\n", siblings2(pmember1, pmember2) ? "true" : "false");
    printf("in main(), pmember1->age: %i\n", pmember1->age);

    printf("FOPEN_MAX = %i\n", FOPEN_MAX);

    return 0;
}
