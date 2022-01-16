/*
 * Created by gt on 11/8/2021 - 11:15.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * va_list:  used in situations in which we need to access optional parameters, and it is an argument list
 *           represents a data object used to hold the parameters corresponding to the ellipsis part of
 *           the parameter list
 *
 * va_start: will connect our argument list with some argument pointer
 *           the list specified in va_list is the first argument and the second argument is the last
 *           fixed parameter
 *
 * var_arg:  will fetch the current argument connected to the argument list
 *           we would need to know the type of the argument that we are reading
 *
 * va_end:   used in situations when we would like to stop using are variable
 *           argument list (cleanup)
 *
 * va_copy:  used in situations for which we need to save our current location
 *
 * void f1(int node_, ...);                 -> valid
 * int f2(const char *s, int k, ...);   -> valid
 * char f3(char c1, ..., char c2);      -> invalid, ellipsis not last
 * double f4(...);                      -> invalid, no parameter
 *
 */

#include <stdio.h>
#include <stdarg.h>

double average(double v1, double v2, ...) {
    va_list parg;
    double sum = v1 + v2;
    double value;
    int count = 2;

    va_start(parg, v2);

    va_list parg_copy;
    va_copy(parg_copy, parg);

    printf("From parg_copy value : %.2lf\n", va_arg(parg_copy, double));

    while ((value = va_arg(parg, double)) != 0.0) {
        sum += value;
        ++count;
    }
    va_end(parg);
    va_end(parg_copy);

    return sum / count;
}

