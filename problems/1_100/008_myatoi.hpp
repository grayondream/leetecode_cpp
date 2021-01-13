#include "ios_include.hpp"

/*
 * @brief 实现自己的atoi，很简单主要要注意边界，防止越界，当然也可以直接使用long
 * long数据类型判断是否大于INT_32MAX和INT_32MIN，这里实现的是比较麻烦的一种，不建议使用long，long数据类型无法保证完全大于int类型和机器字节长度有关
 */
int myAtoi(string s) {
    int i = 0;
    while (s[i] == ' ') { //过滤开头的空格
        i++;
    }

    int len = s.size();
    int neg = 1;
    if (i < len && s[i] == '-') { //判断可能出现的数是不是负数
        neg = -1;
        i++;
    } else if (i < len && s[i] == '+') {
        neg = 1;
        i++;
    }

    int n = 0;
    while (i < len && s[i] <= '9' && s[i] >= '0') {
        n = n * 10 + (int)(s[i] - '0');
        i++;

        if (neg == 1 && i < len && s[i] <= '9' && s[i] >= '0' &&
            n >= 214748364) {
            if ((n == 214748364 && s[i] >= '7') || (n > 214748364))
                return 2147483647;
        } else if (neg == -1 && i < len && s[i] <= '9' && s[i] >= '0' &&
                   n >= 214748364) {
            if ((n == 214748364 && s[i] >= '8') || (n > 214748364))
                return -2147483648;
        }
    }

    return neg * n;
}