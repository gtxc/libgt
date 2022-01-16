/*
 * Created by gt on 11/17/21 - 1:44 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

long long int dec_to_bin(int dec) {
    int remainder;
    long long int result = 0, multiplier = 1;
    while (dec) {
        remainder = dec % 2;
        dec /= 2;
        result += remainder * multiplier;
        multiplier *= 10;
    }
    return result;
}