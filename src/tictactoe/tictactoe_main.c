/*
 * Created by gt on 10/12/21 - 6:59 PM.
 * Copyright (c) 2021 GTXC. All rights reserved.
 */

#include <stdio.h>
#include <stdlib.h>
#define RED "\033[0;31m"
#define NC "\033[0m"

void draw_board(char *moves) {
    system("clear");
    printf("\tTic Tac Toe Game\n\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c   \n", moves[1], moves[2], moves[3]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c   \n", moves[4], moves[5], moves[6]);
    printf("______|______|______\n");
    printf("      |      |      \n");
    printf("   %c  |   %c  |  %c   \n", moves[7], moves[8], moves[9]);
    printf("      |      |      \n");
}

int check_win(const char *moves) {
    return (
            (moves[1] == moves[2] && moves[2] == moves[3]) ||
            (moves[4] == moves[5] && moves[5] == moves[6]) ||
            (moves[7] == moves[8] && moves[8] == moves[9]) ||
            (moves[1] == moves[4] && moves[4] == moves[7]) ||
            (moves[2] == moves[5] && moves[5] == moves[8]) ||
            (moves[3] == moves[6] && moves[6] == moves[9]) ||
            (moves[1] == moves[5] && moves[5] == moves[9]) ||
            (moves[3] == moves[5] && moves[5] == moves[7])
    );
}

int get_move(char *moves) {
    printf("%s - Select number: ", moves[0] == 'X' ? "Player 1 (X)" : "Player 2 (O)");
    char *str = malloc(sizeof *str * 3);
    char *remains;
    fgets(str, 3, stdin);
    int move = (int) strtol(str, &remains, 10);
    free(str);
    if (move && move > 0 && move < 10 && moves[move] == move + 48) {
        moves[move] = moves[0];
        moves[0] = moves[0] == 'X' ? 'O' : 'X';
        return 1;
    }
    return 0;
}

void play_tictactoe() {
    char moves[10] = {'X', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int game = 1;
    int move_cnt = 9;

    do {
        draw_board(moves);
        if (get_move(moves)) {
            --move_cnt;
            if (check_win(moves)) game = 0;
        } else {
            printf("%sInvalid move.%s", RED, NC);
            printf("Press enter to continue...");
            getchar();
            continue;
        }
    } while (game && move_cnt);

    draw_board(moves);
    if (game) {
        printf("Game ended. Draw.\n");
    } else {
        printf("Game ended. %s won.\n", moves[0] == 'X' ? "Player 2 (O)" : "Player 1 (X)");
    }
    printf("Press enter to continue...");
    getchar();
    getchar();
}

int main() {
    play_tictactoe();
    return 0;
}