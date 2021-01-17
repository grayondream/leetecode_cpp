#ifndef STREAM_TOOL_HPP
#define STREAM_TOOL_HPP

#include <iostream>
#include <ostream>
#include <vector>

using std::cout;
using std::endl;
using std::ostream;
using std::vector;

/*
 * @brief 容器常用的和标准输出相交互的工具函数
 */

template <typename T> ostream &operator<<(ostream &os, vector<T> &vec) {
    for (auto val : vec) {
        cout << val << "\t";
    }

    return os;
}

template <typename T> ostream &operator<<(ostream &os, vector<vector<T>> &vec) {
    for (auto v : vec) {
        for (auto e : v) {
            os << e << " ";
        }

        os << endl;
    }

    return os;
}

#endif