#include <iostream>
#include <cstdlib>

#include "004_find_median_sorted_array.hpp"

using std::cout;
using std::endl;


void test()
{
    int times = 4;
    for(int i = times;i > 0;i --)
    {
        cout<<"the "<<i<<"th test!"<<endl;;
        test_004();
    }
}

int main()
{
    std::cout<<"hello leetecode!\n";
    test();
    system("pause");
    return 0;
}