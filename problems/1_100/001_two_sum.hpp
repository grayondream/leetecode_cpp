#include <vector>
#include <map>
#include <algorithm>

using std::sort;
using std::vector;
using std::map;


/*
 * @brief 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
 */


/*
 * @brief 暴力搜索
 * @note 时间复杂度O(n*n)
 */
vector<int> two_sum_force(vector<int> &nums, int target){
    for(int i = 0;i < nums.size();i ++){
        for(int j = i + 1;j < nums.size();j ++){
            if(nums[i] + nums[j] == target)
            {
                return vector<int>{i, j};
            }
        }
    }

    return vector<int>{};
}

/*
 * @brief 使用哈希表进行快速查询，只需要一次循环
 * @note  时间复杂度O(nlogn)，因为需要进行红黑树查找，，运行的时候性能反而不如暴力查找
 */
vector<int> two_sum_hash(vector<int>& nums, int target){
    map<int, int> table;
    for(int i = 0;i < nums.size();i ++){
        table[nums[i]] = i;
    }

    for(int i = 0; i < nums.size();i ++){
        auto it = table.find(target - nums[i]);
        if(it != table.end() && it->second != i){
            return vector<int>{i, it->second};
        }
    }

    return vector<int>{};
}

vector<int> twoSum(vector<int>& nums, int target){
    return two_sum_hash(nums, target);
}

void test_001(){
    
}