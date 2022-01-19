/*
 * Created by gt on 1/19/22 - 5:15 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#ifndef LIBGT_PLAYER_H
#define LIBGT_PLAYER_H
#include <string>
#include <utility>

class Player {
    // attributes
private:
    // no initialization allowed here. Do it in implementation file (Player.cpp).
    static int num_players;
    std::string name;
    int health;
    // methods
public:
    explicit Player(std::string name_val = "None", int health_val = 9);
    std::string get_name();
    void set_name(const std::string &name_val);
    int get_health() const;
    void set_health(int health_val);
    Player(const Player &source);
    ~Player();
    // to access static attributes, define static functions.
    static int get_num_players();
};

#endif //LIBGT_PLAYER_H
