/*
 * Created by gt on 1/17/22 - 3:32 AM.
 * Copyright (c) 2022 GTXC. All rights reserved.
 */

#include <iostream>

using namespace std;

double calc_cost(double base_cost, double tax_rate = 0.06) {
    return base_cost += base_cost * tax_rate;
}

int main() {
    cout << calc_cost(100);
    return 0;
}