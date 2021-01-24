#include "ios_include.hpp"

/*
 * @brief 遍历即可
 */
int findLengthOfLCIS(vector<int> &nums) {
    int max_len = 0;
    int len = nums.size();
    for (int i = 0; i < len;) {
        int j = i + 1;
        while (j < len && nums[j] > nums[j - 1]) {
            j++;
        }

        max_len = max(max_len, j - i);
        i = j;
    }

    return max_len;
}