#include <ostream>
#include <iostream>
#include <vector>

using std::cout;
using std::ostream;
using std::vector;

/*
 * @brief 容器常用的和标准输出相交互的工具函数
 */

template<typename T>
ostream& operator<<(ostream& os, vector<T> &vec){
    for(auto val : vec){
        cout<<val<<"\t";
    }

    return os;
}
