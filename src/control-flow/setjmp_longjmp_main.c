/*
 * Created by gt on 10/22/21 - 10:23 AM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 *
 *
 * setjmp : try
 * longjmp: throw
 *
 * not as like as goto, with goto it can only be possible to jump
 * in the same function, setjmp and longjmp make possible to jump
 * to another functions, anywhere in the program
 *
 * setjmp saves a copy of the program counter and the current pointer to the top of the stack
 *
 * int setjmp(jmp_buf j)
 *     use the variable j to remember where you are now
 *     must be called first
 *
 * longjmp is then invoked after setjmp (longjmp(jmp_buf j, int i))
 *     says go back to the place that the j is remembering
 *     restores the process in the state that it exited when it called setjmp
 *     returns the value of i so the code can tell when you actually got back here via longjmp()
 *     the content of the j are destroyed when it used in a longjmp()
 *
 * often referred to as "unwinding the stack" because you unroll activation records from the stack
 * until you get to the saved one
 *
 * the header file <setjmp.h> need to be included in any source file that uses setjmp or longjmp
 *
 */

#include <stdio.h>
#include <setjmp.h>
#include <stdlib.h>

jmp_buf buf;

void myFunction() {
    printf("myFunction() called.\n");
    longjmp(buf, 0);
    /* NOT REACHED */
    printf("You will never see this, because I longjmp'd\n");
}

int main() {

    //below block comment another example for setjmp-longjmp
/*
    int i = setjmp(buf);
    printf("i = %i\node_", i);
    if (i != 0) exit(0);
    longjmp(buf, 42);
    printf("Does this line get printed?\node_");
*/
    if (setjmp(buf)) {
        printf("setjmp(buf) = %i\n", setjmp(buf));
        printf("Back in main.\n");
    } else {
        printf("First time through.\n");
        myFunction();
    }
    return 0;
}
