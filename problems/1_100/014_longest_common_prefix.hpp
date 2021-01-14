#include "ios_include.hpp"

/*
 * @brief 最长公共子串
 * @note 按顺序遍历即可
 */

string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty())
        return "";
    string ret;
    for (int i = 0;; i++) {
        if (i > int(strs[0].size()) - 1)
            return ret;

        char key = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (i > int(strs[j].size() - 1) || strs[j][i] != key) {
                return ret;
            }
        }

        ret += string(1, key);
    }

    return ret;
}

void test_014() {
    vector<string> str = {""};
    string ret = longestCommonPrefix(str);
    cout << ret << endl;
}