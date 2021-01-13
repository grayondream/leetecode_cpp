#include "ios_include.hpp"

/*
 * @brief 给你一个字符串 s，找到 s 中最长的回文子串。
 * @note
 * 回文串的特点将左右同时删除多个字符，这个字符串同样是回文串，利用这个特性进行遍历，需要处理两种情况，一种是回文串以一个字符为中心向两侧扩展，比如'aba'，这种直接遍历即可，另一是以空格为中心向两侧扩展比如'aa'，此时可扩展数组（并不实际扩展只是概念上）的长度，就像每两个字符之间插入一个空格字符一般
 */
string longestPalindrome(string s) {
    int len = s.size();
    int max_ret = 0;
    string ret;
    for (int i = 0; i < 2 * len - 1; i++) {
        int left = 0;
        int right = 0;
        int cnt = 0;
        if ((i & 1) == 0) { //如果当前下标为偶数表明是以一个字符为中心
            left = i / 2 - 1;
            right = i / 2 + 1;
            cnt = 1;
        } else { //下标为奇数表示以空格为中心
            left = i / 2;
            right = (i + 1) / 2;
            cnt = 0;
        }

        while (left >= 0 && right <= len - 1 && s[left] == s[right]) {
            cnt += 2;
            left--;
            right++;
        }

        max_ret = max(max_ret, cnt);
        if (max_ret == cnt) {
            ret = string(s.begin() + left + 1, s.begin() + right);
        }
    }

    return ret;
}

void test_005() {
    string ret = "babad";
    ret = longestPalindrome(ret);
    cout << ret << endl;
}