/*
 * Created by gt on 1/22/22 - 7:50 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <utility>
#include "Movie.h"

Movie::Movie() {}

Movie::Movie(std::string name, std::string rating, int watched)
    : name(std::move(name)), rating(std::move(rating)), watched(watched) {}

Movie::Movie(const Movie &source)
    : Movie {source.name, source.rating, source.watched}{}

Movie::~Movie() = default;

const std::string &Movie::get_name() const {
    return name;
}

void Movie::set_name(const std::string &name) {
    Movie::name = name;
}

const std::string &Movie::get_rating() const {
    return rating;
}

void Movie::set_rating(const std::string &rating) {
    Movie::rating = rating;
}

int Movie::get_watched() const {
    return watched;
}

void Movie::set_watched(int watched) {
    Movie::watched = watched;
}

void Movie::increment_watched() {
    ++watched;
}

void Movie::display() const {
    std::cout << name << ", " << rating << ", " << watched << std::endl;
}

