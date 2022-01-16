/*
 * Created by gt on 1/13/22 - 7:54 PM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

/*
 * use only what you need:
 * using std::cout
 * using std::cin
 * using std::endl
 *
 */

int main() {
    cout << "Tell me anything: ";
    char *s = (char *) malloc(sizeof *s * 50);
    cin >> s;
    cout << "You are telling me, \"" << s << "\", right?" << endl;

    return 0;
}