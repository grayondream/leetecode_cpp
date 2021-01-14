#include "ios_include.hpp"

/*
 * @brief Z 字形变换
 * @note  n行字符中|/中|方向同行两个字符之间的间隔为2*(n - 1)，而斜方向第一行和最后一行没有斜方向的元素
 *            j
 * 0  |   /|   /|   /|
 *    |  / |  / |  / |
 *    | /  | /  | /  |
 * n  |/   |/   |/   |
 */
string convert(string s, int numRows) {
    if (numRows == 1)
        return s;
    string ret;
    int len = s.size();
    int gap = 2 * (numRows - 1);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j + i < len; j += gap) {
            ret += s[j + i];                                       // z字垂直方向的字符
            if (i != 0 && i != numRows - 1 && j + gap - i < len) { // z字斜方向的字符
                ret += s[j + gap - i];
            }
        }
    }

    return ret;
}