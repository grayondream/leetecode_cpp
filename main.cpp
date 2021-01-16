#include <cstdlib>
#include <iostream>

#include "803_bricks_falling_when_hit.hpp"

using std::cout;
using std::endl;

void test() {
    int times = 1;
    for (int i = times; i > 0; i--) {
        cout << "the " << i << "th test!" << endl;
        test_803();
    }
}

int main() {
    std::cout << "hello leetecode!\n";
    test();
    system("pause");
    return 0;
}