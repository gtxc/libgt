/*
 * Created by gt on 1/16/22 - 4:13 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>

using namespace std;

int main() {
    string pyr = "C++ is Fun";
    int size = (int) pyr.length();
    string spc (size - 1, ' ');
    for (int i = 0; i < size; ++i) {
        cout << spc.substr(0, size - 1 - i);
        cout << pyr.substr(0, i + 1);
        cout << string(pyr.rbegin(),pyr.rend()).substr(size - i);
        cout << spc.substr(0, size - 1 - i);
        cout << endl;
    }


    return 0;
}


// Letter Pyramid
// Written by Frank J. Mitropoulos

#include <iostream>
#include <string>


/*
instructor solution
int main()
{
    std::string letters{};

    std::cout << "Enter a string of letters so I can create a Letter Pyramid from it: ";
    getline(std::cin, letters);

    size_t num_letters = letters.length();

    int position {0};

    // for each letter in the string
    for (char c: letters) {

        size_t num_spaces = num_letters - position;
        while (num_spaces > 0) {
            std::cout << " ";
            --num_spaces;
        }

        // Display in order up to the current character
        for (size_t j=0; j < position; j++) {
            std::cout << letters.at(j);
        }

        // Display the current 'center' character
        std::cout << c;

        // Display the remaining characters in reverse order
        for (int j=position-1; j >=0; --j) {
            // You can use this line to get rid of the size_t vs int warning if you want
            auto k = static_cast<size_t>(j);
            std::cout << letters.at(k);
        }

        std::cout << std::endl; // Don't forget the end line
        ++position;
    }

    return 0;
}
*/
