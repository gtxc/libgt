/*
 * Created by gt on 1/19/22 - 4:43 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 *
 * Consider a class that contains a pointer as a data member.
 * Constructor allocates storage dynamically and initializes the pointer.
 * Destructor releases the memory allocated by the constructor.
 * What happens in the default copy constructor?
 * Shallow copy is the default copy constructor.
 * Member-wise copy.
 * Each data member is copied from the source object.
 * The pointer is copied NOT what it points to (shallow copy).
 * Problem:
 *  source and the newly created object BOTH point to the SAME data area.
 *  when we release the storage in the destructor, the other object still refers to the released storage.
 */

#include <iostream>

using namespace std;

class Shallow {
private:
    int *data;
public:
    int get_data_value() {return *data;}
    void set_data_value(int d) {*data = d;}
    explicit Shallow(int d); // constructor
    Shallow(const Shallow &source); // copy constructor
    ~Shallow(); // destructor
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source)
    : data(source.data) {
        cout << "copy constructor - shallow copy" << endl;
}

Shallow::~Shallow() {
    delete data;
    cout << "destructor freeing data" << endl;
}

void display_shallow(Shallow s) {
    cout << s.get_data_value() << endl;
}

int main() {
    Shallow obj1 {100};
    display_shallow(obj1);

    Shallow obj2 {obj1};
    obj2.set_data_value(1000);
    return 0;
}