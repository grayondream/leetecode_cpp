#include <cstdlib>
#include <iostream>

#include "1584_min_cost_connect_all_points.hpp"

using std::cout;
using std::endl;

void test() {
    int times = 1;
    for (int i = times; i > 0; i--) {
        cout << "the " << i << "th test!" << endl;
        // test_1584();
        test_graph();
    }
}

int main() {
    std::cout << "hello leetecode!\n";
    test();
    system("pause");
    return 0;
}