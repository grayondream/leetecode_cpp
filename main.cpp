#include <cstdlib>
#include <iostream>

#include "014_longest_common_prefix.hpp"

using std::cout;
using std::endl;

void test() {
    int times = 1;
    for (int i = times; i > 0; i--) {
        cout << "the " << i << "th test!" << endl;
        test_014();
    }
}

int main() {
    std::cout << "hello leetecode!\n";
    test();
    system("pause");
    return 0;
}