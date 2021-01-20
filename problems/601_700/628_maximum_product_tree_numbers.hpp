#include "ios_include.hpp"

/*
 * @brief 给定一个整型数组，在数组中找出由三个数组成的最大乘积，并输出这个乘积
 * @note 排序之后找最大三个数乘积，最小两个数和最大数的乘积中的最大值
 */
int maximumProduct_sort(vector<int> &nums) {
    int len = nums.size();
    sort(nums.begin(), nums.end());
    int max_ret1 = nums[len - 1] * nums[len - 2] * nums[len - 3];
    int max_ret2 = nums[0] * nums[1] * nums[len - 1];
    return max(max_ret1, max_ret2);
}

/*
 * @brief 线性扫描找到最大的三个值和最小的两个值
 */
int maximumProduct(vector<int> &nums) {
    int len = nums.size();
    int min1 = INT32_MAX, min2 = INT32_MAX;                   // min1 <= min2
    int max1 = INT32_MIN, max2 = INT32_MIN, max3 = INT32_MIN; // max1<max2<max3
    for (int val : nums) {
        if (val < min1) {
            min2 = min1;
            min1 = val;
        } else if (val < min2) {
            min2 = val;
        }

        if (val > max3) {
            max1 = max2;
            max2 = max3;
            max3 = val;
        } else if (val > max2) {
            max1 = max2;
            max2 = val;
        } else if (val > max1) {
            max1 = val;
        }
    }

    return max(max1 * max2 * max3, max3 * min1 * min2);
}