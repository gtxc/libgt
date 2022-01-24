/*
 * Created by gt on 1/22/22 - 7:50 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <utility>
#include "Movies.h"

using namespace std;

Movies movieList;

void add_movie(const string& name, const string& rating, int watched) {
    if (movieList.add_movie(name, rating, watched)) {
        cout << name << " added to the list" << endl;
    } else {
        cout << name << " already exist in the list" << endl;
    }
}

void increment_watched(const string& name) {
    if (movieList.increment_watched(name)) {
        cout << name << " incremented by 1" << endl;
    } else {
        cout << "Movie is not found";
    }
}

void display_movies() {
    movieList.display();
}

int main() {
    add_movie("Shutter Island", "PG", 3);
    add_movie("Matrix", "PG-13", 0);
    increment_watched("Shutter Island");
    increment_watched("Matrix");
    increment_watched("Matrix");
    increment_watched("Matrix");
    display_movies();
    return 0;
}
