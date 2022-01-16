/*
 * Created by gt on 11/17/21 - 3:33 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

_Bool is_prime(int n) {
    if (n == 2)
        return 1;

    if (n < 5)
        return 0;

    for (int i = 2; i < n / 2; i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}
