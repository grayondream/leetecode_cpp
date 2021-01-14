#include "ios_include.hpp"

/*
 * @brief 给定由若干 0 和 1 组成的数组 A。我们定义 N_i：从 A[0] 到 A[i] 的第 i
 * 个子数组被解释为一个二进制数（从最高有效位到最低有效位）
 * @note 题解主要是数学知识O(n)
 */
vector<bool> prefixesDivBy5(vector<int> &A) {
    vector<bool> ret;
    int len = A.size();
    long long val = 0;
    for (int i = 0; i < len; i++) {
        val = ((val << 1) + A[i]) % 5;
        ret.push_back(val == 0);
    }

    return ret;
}