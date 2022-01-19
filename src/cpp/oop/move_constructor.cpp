/*
 * Created by gt on 1/19/22 - 7:06 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * Sometimes copy constructors are called many times automatically due to the copy semantics C++.
 * Copy constructors doing deep copying can have a significant performance bottleneck.
 * C++11 introduced move semantics and the move constructor.
 * Move constructor moves an object rather than copy it.
 * Optional but recommended when you have a raw pointer.
 * Copy elision - C++ may optimize copying away completely (RVO - Return Value Optimization).
 *
 * r-value reference : &&
 *
 * instead of making a deep copy of the move constructor
 * moves the resource on the heap
 * simply copies the address of the resource from source to the current object
 * and, null out the pointer in the source pointer
 *
 */

#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data; // raw pointer
public:
    void set_data_value(int d) {*data = d;}
    int get_data_value() {return *data;}
    explicit Move(int d); // constructor
    Move(const Move &source); // copy constructor
    Move(Move &&source) noexcept; // move constructor
    ~Move(); // destructor
};

Move::Move(int d) {
    data = new int;
    *data = d;
    cout << "constructor for: " << d << endl;
}

Move::Move(const Move &source)
    : Move {*source.data} {
        cout << "copy constructor - deep copy for: " << *data << endl;
}

Move::Move(Move &&source) noexcept
    : data {source.data} {
        source.data = nullptr;
        cout << "move constructor - moving resource: " << *data << endl;
}

Move::~Move() {
    if (data != nullptr) {
        cout << "destructor freeing data for: " << *data << endl;
    } else {
        cout << "destructor freeing data for nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;
    vec.push_back(Move{10});
    vec.push_back(Move{20});
    vec.push_back(Move{30});
    vec.push_back(Move{40});
    vec.push_back(Move{50});
    vec.push_back(Move{60});
    vec.push_back(Move{70});
    vec.push_back(Move{80});

    return 0;
}