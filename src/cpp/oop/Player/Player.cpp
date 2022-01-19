/*
 * Created by gt on 1/19/22 - 5:15 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include "Player.h"

int Player::num_players {0};

std::string Player::get_name() {
    return this->name;
}

void Player::set_name(const std::string &name_val) {
    this->name = name_val;
}

int Player::get_health() const {
    return this->health;
}

void Player::set_health(const int health_val) {
    this->health = health_val;
}

Player::Player(std::string name_val, int health_val)
    : name {std::move(name_val)}, health {health_val} {
        // increment static variable in constructor
        ++num_players;
}

Player::Player(const Player &source)
//    : name {source.name}, health {source.health} {
// delegation
    : Player {source.name, source.health} {
    std::cout << "Copy constructor called - made copy of: " << source.name << std::endl;
}

Player::~Player() {
    std::cout << "Destructor called for " << this->get_name() << std::endl;
    // decrement static attributes here
    --num_players;
}

// no need to use static here
int Player::get_num_players() {
    return num_players;
}