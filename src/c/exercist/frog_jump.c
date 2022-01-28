/*
 * Created by gt on 1/28/22 - 1:57 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <stdio.h>

int solution(int X, int Y, int D) {
    return ((Y-X) / D) + ((Y-X) % D > 0);
}

int main() {
    printf("Minimum required jump: %i\n", solution(10, 85, 30));
    return 0;
}