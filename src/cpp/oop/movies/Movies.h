/*
 * Created by gt on 1/22/22 - 8:06 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#ifndef LIBGT_MOVIES_H
#define LIBGT_MOVIES_H

#include <vector>
#include "Movie.h"

class Movies{
private:
    std::vector<Movie> *movies{};
public:
    Movies();

    ~Movies();

    bool add_movie(const std::string& name, const std::string& rating, int watched);

    bool increment_watched(const std::string& name);

    void display() const;
};


#endif //LIBGT_MOVIES_H
