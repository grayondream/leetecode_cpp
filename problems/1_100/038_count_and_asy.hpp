#include "ios_include.hpp"

/*
 * @brief 给定一个正整数 n ，输出外观数列的第 n 项。
 * @note    思路很简单就是计数再转字符串
 */
string generate_str(string s){
    int len = s.size();
    string ret;
    for(int i = 0;i < len;i ++){
        int cnt = 1;
        int key = s[i];
        while(i < len - 1 && s[i + 1] == key){
            cnt++;
            i++;
        }

        ret += to_string(cnt) + string(1, key);
    }

    return ret;
}

string countAndSay(int n) {
    string ret("1");
    for(int i = 2; i <= n;i ++){
        ret = generate_str(ret);
    }

    return ret;
}