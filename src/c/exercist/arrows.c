/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

int task1(char *S) {
    int directions[4] = {0}, mostCommon = 0, length_S = 0;
    while (*S != '\0') {
        switch (*S) {
            case '>':
                ++directions[0];
                break;
            case 'v':
                ++directions[1];
                break;
            case '<':
                ++directions[2];
                break;
            case '^':
                ++directions[3];
                break;
            default:
                break;
        }
        ++S;
        ++length_S;
    }
    for (int i = 0; i < 4; ++i) {
        if (mostCommon < directions[i]) {
            mostCommon = directions[i];
        }
    }
    return length_S - mostCommon;
}

int main() {
    char S[] = ">>>vvv<<<^^^";
    int charToTurn = task1(S);
    printf("\nRotate %i element(s)\n", charToTurn);
    return 0;
}
