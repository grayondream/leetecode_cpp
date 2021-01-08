
/*
 * @brief 判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
 * @note 时间复杂度 n
 */

bool isPalindrome(int x) {
    if(x < 0)   return false;
    int n = 1;
    while(x / n >= 10){
        n *= 10;
    }

    while(x > 0){
        int top = x / n;
        int low = x % 10;
        if(top != low)
            return false;

        x = x - low - top * n;
        x = x / 10;
        n /= 100;
    }

    return true;
}

#include <iostream>
using namespace std;
void test_009(){
    cout<<isPalindrome(1234567899)<<endl;
}