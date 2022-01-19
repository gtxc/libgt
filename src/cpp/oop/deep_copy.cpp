/*
 * Created by gt on 1/19/22 - 5:19 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * Create a copy of the pointed-to data.
 * Each copy will have a pointer to unique storage in the heap.
 * Deep copy when you have a raw pointer as a class data member.
 *
 */

#include <iostream>

using namespace std;

class Deep {
private:
    int *data;
public:
    int get_data_value() {return *data;}
    void set_data_value(int d) {*data = d;}
    explicit Deep(int d); // constructor
    Deep(const Deep &source); // copy constructor
    ~Deep(); // destructor
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

Deep::Deep(const Deep &source)
    // delegate
    : Deep{*source.data} {
//    data = new int;
//    *data = *source.data;
    cout << "copy constructor - deep copy" << endl;
}

Deep::~Deep() {
    delete data;
    cout << "destructor freeing data" << endl;
}

void display_deep(Deep d) {
    cout  << d.get_data_value() << endl;
}

int main() {
    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 {obj1};
    obj2.set_data_value(1000);
    return 0;
}