/*
 * Created by gt on 1/19/22 - 7:57 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include "Player.h"

using namespace std;

void display_player(Player p) {
    cout << "name: " << p.get_name() << endl;
    cout << "health: " << p.get_health() << endl;
}

void display_active_players() {
    cout << "active player: " << Player::get_num_players() << endl;
}

int main() {
    Player gg;
    display_player(gg);
    cout << gg.get_name() << endl;
    Player gt = Player("Orc", 23);
    display_active_players();
    cout << gt.get_name() << endl;
    cout << gt.get_health() << endl;
    gt.set_name("Elf");
    gt.set_health(100);
    cout << gt.get_name() << endl;
    cout << gt.get_health() << endl;
    display_player(gt);
    Player copy_of_gt {gt};
    display_active_players();
    return 0;
}
