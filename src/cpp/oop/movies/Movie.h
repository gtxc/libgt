/*
 * Created by gt on 1/22/22 - 7:50 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#ifndef LIBGT_MOVIE_H
#define LIBGT_MOVIE_H
#include <string>

class Movie{
private:
    std::string name;
    std::string rating;
    int watched{};
public:
    Movie();

    Movie(std::string name, std::string rating, int watched);

    Movie(const Movie &source);

    ~Movie();

    const std::string &get_name() const;

    void set_name(const std::string &name);

    const std::string &get_rating() const;

    void set_rating(const std::string &rating);

    int get_watched() const;

    void set_watched(int watched);

    void increment_watched();

    void display() const;
};


#endif //LIBGT_MOVIE_H
