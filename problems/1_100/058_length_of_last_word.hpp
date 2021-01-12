#include "ios_include.hpp"

/*
 * @brief 给定一个仅包含大小写字母和空格 ' ' 的字符串 s，返回其最后一个单词的长度。如果字符串从左向右滚动显示，那么最后一个单词就是最后出现的单词。
 * @note    从末尾往前判断即可，需要过滤末尾的空格
 */
int lengthOfLastWord(string s) {
    int end = s.size() - 1;
    //第一步过滤末尾的空格
    while(end >= 0 && s[end] == ' '){
        end--;
    }

    int start = end;
    while(start >= 0 && s[start] != ' '){
        start --;
    }

    return end - start;
}