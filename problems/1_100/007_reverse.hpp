
#include <stdint.h>

/*
 * @brief 给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。
 * @note    时间复杂度O(|n|)
 */
int reverse(int x) {
    int ret = 0;
    while (x) {
        if (ret > INT32_MAX / 10 || ret == INT32_MAX / 10 && x % 10 > 7)
            return 0;
        if (ret < INT32_MIN / 10 || ret == INT32_MIN / 10 && x % 10 < -8)
            return 0;

        ret = ret * 10 + x % 10;
        x /= 10;
    }

    return ret;
}

#include <iostream>
void test_007() {
    using std::cout;
    using std::endl;
    cout << reverse(-2147483412) << endl;
}