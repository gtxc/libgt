/*
 * Created by gt on 1/19/22 - 8:19 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <string>
#include <utility>

using namespace std;

class Player {
private:
    string name;
    int health;
    int xp;
public:
    string get_name() const {return name;}
    void set_name(string name_val) {name = std::move(name_val);}
    Player();
    explicit Player(string name_val);
    Player(string name_val, int health_val, int xp_val);
};

Player::Player()
    : Player {"None", 0, 0} {}

Player::Player(string name_val)
    : Player {std::move(name_val), 0, 0} {}

Player::Player(string name_val, int health_val, int xp_val)
    : name{std::move(name_val)}, health{health_val}, xp{xp_val} {}

void display_player_name(const Player &p) {
    cout << p.get_name() << endl;
}

int main() {
    const Player villian{"Villian", 100, 55};
    Player orc {"Orc", 100, 15};
    orc.set_name("Not Orc");
    display_player_name(villian);
    display_player_name(orc);
    return 0;
}
