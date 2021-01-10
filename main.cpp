#include <iostream>
#include <cstdlib>

#include "024_reverse_list.hpp"

using std::cout;
using std::endl;


void test()
{
    int times = 1;
    for(int i = times;i > 0;i --)
    {
        cout<<"the "<<i<<"th test!"<<endl;;
        test_024();
    }
}

int main()
{
    std::cout<<"hello leetecode!\n";
    test();
    system("pause");
    return 0;
}