/*
 * Created by gt on 10/21/21 - 10:59 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdbool.h>

/* line styles */
#define SOLID   0
#define DOTTED  1
#define DASHED  2

/* primary colors */
#define RED     1
#define GREEN   2
#define BLUE    4

/* mixed colors */
//#define BLACK 0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
//#define CYAN (GREEN | BLUE)
#define WHITE (RED | GREEN | BLUE)

const char *colors[8] = {"black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"};

struct box_props {
    bool opaque:                        1;
    unsigned short int fill_color:      3;
    unsigned short int:                 4;
    bool show_border:                   1;
    unsigned short int border_color:    3;
    unsigned short int border_style:    2;
    unsigned short int:                 2;
};

void show_settings(const struct box_props *pb) {
    printf("Box is %s.\n", pb->opaque ? "opaque" : "transparent");
    printf("The fill color is %s.\n", colors[pb->fill_color]);
    printf("Border %s.\n", pb->show_border ? "shown" : "not shown");
    printf("The border color is %s.\n", colors[pb->border_color]);
    printf("The border style is ");

    switch (pb->border_style) {
        case SOLID: printf("solid.\n"); break;
        case DOTTED: printf("dotted.\n"); break;
        case DASHED: printf("dashed.\n"); break;
        default: printf("unknown type.\n");
    }
}

int main() {
    struct box_props box = {true, YELLOW, true, GREEN, DASHED};
    printf("sizeof bp %li\n", sizeof box);
    printf("Original box settings:\n");
    show_settings(&box);

    box.opaque = false;
    box.fill_color = WHITE;
    box.border_color = MAGENTA;
    box.border_style = SOLID;

    printf("\nModified settings:\n");
    show_settings(&box);
    return 0;
}