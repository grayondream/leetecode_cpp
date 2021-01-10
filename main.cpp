#include <iostream>
#include <cstdlib>

#include "022_get_kth_from_end.hpp"

using std::cout;
using std::endl;


void test()
{
    int times = 1;
    for(int i = times;i > 0;i --)
    {
        cout<<"the "<<i<<"th test!"<<endl;;
        test_022();
    }
}

int main()
{
    std::cout<<"hello leetecode!\n";
    test();
    system("pause");
    return 0;
}