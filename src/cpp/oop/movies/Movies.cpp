/*
 * Created by gt on 1/22/22 - 8:06 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include "Movies.h"
#include "Movie.h"

Movies::Movies() {
    movies = new std::vector<Movie>;
}

Movies::~Movies() = default;

bool Movies::add_movie(const std::string& name, const std::string& rating, int watched) {
    if (movies) {
        for (const auto &movie : *movies) {
            if (movie.get_name() == name) {
                return false;
            }
        }
        Movie newMovie {name, rating, watched};
        (*movies).push_back(newMovie);
        return true;
    }
    return false;
}

bool Movies::increment_watched(const std::string& name) {
    if (movies) {
        for (auto &movie : *movies) {
            if (movie.get_name() == name) {
                movie.increment_watched();
                return true;
            }
        }
    }
    return false;
}

void Movies::display() const {
    if (movies) {
        if (!(*movies).empty()) {
            for (const auto& movie : *movies) {
                movie.display();
            }
        } else {
            std::cout << "There is no movie in the movies list" << std::endl;
        }
    }
}
