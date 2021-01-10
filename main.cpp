#include <iostream>
#include <cstdlib>

#include "707_design_linklist.hpp"

using std::cout;
using std::endl;


void test()
{
    int times = 4;
    for(int i = times;i > 0;i --)
    {
        cout<<"the "<<i<<"th test!"<<endl;;
        test_707();
    }
}

int main()
{
    std::cout<<"hello leetecode!\n";
    test();
    system("pause");
    return 0;
}