#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

/*
 * @brief 暴力搜索
 * @note 时间复杂度：O(n * n)
 */
int lolss_force(const string &s){
    int max_len = 0;
    int table[256] = {0};
    for(int i = 0;i < s.size();i ++){
        int j = i;
        for(j = i;j < s.size() && table[s[j]] == 0;j ++){
            table[s[j]] = 1;
        }

        max_len = max_len > j - i ? max_len : j - i;
        memset(table, 0, sizeof(int) * 256);
    }

    return max_len;
}

/*
 * @brief 使用哈希表表示当前子窗口的字符，然后当遇到重复时进位左指针
 * @note 时间复杂度O(n)
 */
int lolss_hash(const string &s){
    int table[256] = {0};
    int max_len = 0;
    int left = 0, right = 0;
    while(left < s.size() && right < s.size()){
        //寻找下一个重复元素
        for(;right < s.size() && table[s[right]] == 0;right++){
            table[s[right]] = right + 1;
        }

        //更新最大长度，并移动左指针
        max_len = max_len > right - left ? max_len : right - left;
        while(right < s.size() && left < s.size() && left <= table[s[right]]){
            table[s[left++]] = 0;
        }
    }

    return max_len;
}

int lengthOfLongestSubstring(const string &s){
    
    return lolss_hash(s);
}

void test_003(){
    string s = "";
    int ret = lengthOfLongestSubstring(s);
    cout<<ret<<endl;
}