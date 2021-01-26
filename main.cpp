#include <cstdlib>
#include <iostream>

#include "010_regular_expression_matching.hpp"
#include "ios_include.hpp"

using std::cout;
using std::endl;

void test() {
    int times = 1;
    for (int i = times; i > 0; i--) {
        cout << "the " << i << "th test!" << endl;
        // test_1584();
        test_010();
    }
}

int main() {
    std::cout << "hello leetecode!\n";
    test();
    system("pause");
    return 0;
}