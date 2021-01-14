#include "ios_include.hpp"

/*
 * @biref 暴力求解,会超时
 * @note O(n * n)
 */
int max_area_force(vector<int> &height) {
    int len = height.size();
    int ret_max = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            int cur = min(height[i], height[j]) * (j - i);
            ret_max = max(ret_max, cur);
        }
    }

    return ret_max;
}

/*
 * @brief 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和
 * (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
 * @note 双指针遍历
 */
int max_area(vector<int> &height) {
    int len = height.size();
    int ret = 0;
    int left = 0, right = len - 1;
    while (left < right) {
        if (height[left] < height[right]) {
            ret = max(ret, (right - left) * height[left]);
            left++;
        } else {
            ret = max(ret, (right - left) * height[right]);
            right--;
        }
    }

    return ret;
}