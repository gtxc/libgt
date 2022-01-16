/*
 * Created by gt on 11/11/2021 - 9:52.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>

// PREDEFINED MACROS
// __FILE__ : current file name (string)
// __LINE__ : current line number of the current source code (an integer constant)
// __func__ : name of any function when placed inside a function of the current file (not part of the standard)
// __DATE__ : date of the source file in string form Mmm dd yyy: Jan 19 2002
// __TIME__ : the time the source file was compiled as string hh:mm:ss
// __STDC__ : used to indicate if the compiler supports standard C by returning the value 1



#define Warning(...) fprintf(stderr, __VA_ARGS__)

#define UPTO(i, n) for ((i) = 0; (i) < (n); ++(i))

#define IS_UPPER(x) ((x) >= 'A' && (x) <= 'Z')
#define IS_LOWER(x) ((x) >= 'a' && (x) <= 'z')

#define PRNT(a, b) \
    printf("value 1 = %i\n", a); \
    printf("value 2 = %i\n", b);

#define HELLO(x) printf("Hello, " #x "\n");
#define PRINTINT(var) printf(#var " = %i\n", var);
#define CONCATENATE(x,y) x##y

#define DECLARESORT(prefix, type) \
static int                        \
_DeclareSort_ ## prefix ## _Compare(const void *a, const void *b) { \
    const type *aa; const type *bb; \
    aa = a; bb = b; \
    if (aa < bb) return -1;       \
    else if (bb < aa) return 1;   \
    else return 0;                \
}                                 \
                                  \
void                              \
prefix ## _sort(type *a, int n) { \
    qsort(a, sizeof (type), n, _DeclareSort_ ## prefix ## _Compare);\
}

#include <stdlib.h>

DECLARESORT(int, int)

void test_function() {
    printf("%s was called.\n", __func__);
}

int main() {

    Warning("%s: This program is here\n", "GT");

    int x = 2, y = 3;

    PRNT(2, 3);
    int j;
    UPTO(j, 4) {
        printf("j value is %i\n", j);
    }

    HELLO(GT);
    int gt = 3;
    PRINTINT(gt);

    int xy = 10;
    printf("%i\n", CONCATENATE(x,y));


    int xxx =5;
    int *a = &xxx;
    int n = 6;

    PRINTINT(*a);
    PRINTINT(xxx);
    PRINTINT(n);

    printf("%s was called.\n", __func__);
    printf("Program last compiled at %s on %s\n", __TIME__, __DATE__);
    test_function();

    #if (__STDC__)
        printf("Implementation is ISO-conforming.\n");
    #else
        printf("Implementation is not ISO-conforming.\node_");
    #endif

    printf("File is %s line is %i\n", __FILE__, __LINE__);

    return 0;
}