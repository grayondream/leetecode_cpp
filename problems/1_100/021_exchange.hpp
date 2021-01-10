#include "ios_include.hpp"

/*
 * @brief 将数组中奇数放置在偶数前面，直接遍历交换即可
 * @note  O(n)
 */
vector<int> exchange(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right){
        while ((nums[left] & 1) == 1 && left < right){
            left++;
        }
        
        while (((nums[right] & 1) == 0) && left < right){
            right --;
        }
        
        if(left < right){
            swap(nums[left], nums[right]);
        }
    }
    
    return nums;
}

void test_021(){
    vector<int> vec = generate_container<vector<int>>(10);
    cout<<vec<<endl;
    vec = exchange(vec);
    cout<<vec<<endl;
}