#include <vector>
#include <algorithm>

using std::sort;
using std::vector;

/*
 * @brief 给定两个大小为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的中位数。
 * @note    暴力求解将两个数组合并然后排序进行取中间的数值，时间复杂度O(nlogn)
 */
double find_media_force(vector<int> &nums1, vector<int> &nums2){
    for(auto val : nums2){
        nums1.push_back(val);
    }

    sort(nums1.begin(), nums1.end())   ;
    if(nums1.size() & 1 == 1){
        return nums1[int(nums1.size() / 2)];
    }
    else{
        return (nums1[int(nums1.size() / 2)] + nums1[int(nums1.size() / 2) - 1]) / 2.0;
    }
}

/*
 * @brief   对于两个有序数组，进行顺序遍历，遍历时选择较小者进行前进，直到遍历元素数量达到两个数组的长度综合的1/2
 * @note    时间复杂度O(n)
 */
double find_media_bipointer(vector<int> &nums1, vector<int> &nums2){
    int len1 = nums1.size(), len2 = nums2.size();
    int total_len = len1 + len2;
    int start1 = 0, start2 = 0;
    int left = 0, right = 0;
    for(int i = 0;i <= int(total_len / 2);i ++){
        left = right;
        if(start1 < len1 && (start2 >= len2 || nums1[start1] <= nums2[start2])){
            right = nums1[start1++];
        }else{
            right = nums2[start2++];
        }
    }

    if((total_len & 1) == 0){
        return (right + left) / 2.0;
    }else{
        return right;
    }
}

/*
 * @brief 中位数是将一个数列划分为两半，左半部份的所有元素小于等于有半部分的所有元素，二分法首相从中间进行二分，然后在此的基础上不断逼近最终的可靠结果，拆分时因为数组是有序的，nums1[0 ~ i-1]和nums2[0 ~ j-1]是右=左半部分，nums2[j ~ len2)和nums1[i ~ len1)是右半部份，当左半部份的最大值小于有半部分的最小值时
 */
double find_media_bin(vector<int> &nums1, vector<int> &nums2){
    if(nums1.size() > nums2.size())             //保证第一个数组比第二个数组size小,因为计算j时使用了(len1+len2+1)/2 - i，当i取len1时如果第一个数组大可能溢出
        return find_media_bin(nums2, nums1);

    int len1 = nums1.size();
    int len2 = nums2.size();
    int total_len = len1 + len2;
    int left = 0;
    int right = nums1.size();
    int med1 = 0, med2 = 0;
    while(left <= right){
        int i = (left + right) / 2;
        int j = (total_len + 1) / 2 - i;                   //i,j分表表示在两个数组中的切分位置，如此选值是因为i和j的位置始终保证拆分的左半部份和右半部份元素量相等，即i + j = (len1 + len2 - i - j + 1）奇数，i + j = (len1 + len2 - i - j)偶数，因为c++整形和float的转换的截断因此可以合在一起写

        //进行过边界处理
        int nums1_i_1 = (i == 0 ? INT32_MIN : nums1[i - 1]);
        int nums2_j_1 = (j == 0 ? INT32_MIN : nums2[j - 1]);
        int nums1_i   = (i == len1 ? INT32_MAX : nums1[i]);
        int nums2_j   = (j == len2 ? INT32_MAX : nums2[j]);
        if(nums1_i_1 <= nums2_j){           //如果nums1_i_1 <= nums2_j能够保证左右两边都满足左边的元素都小于右边，因为完整条件为nums1_i_1<=nums2_j && nums2_j_1 <= nums1_i，当第一个条件满足时第二个条件一定满足，因为i是不断增大的，而j是不断减小的
            med1 = nums1_i_1 > nums2_j_1 ? nums1_i_1 : nums2_j_1;           //左侧最大值
            med2 = nums1_i < nums2_j ? nums1_i : nums2_j;                   //右侧最小值
            left = i + 1;
        }else{
            right = i - 1;
        }
    }

    if((total_len & 1) == 1){
        return med1;
    }else{
        return (med1 + med2) / 2.0;
    }
}


double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    return find_media_bin(nums1, nums2);
}

#include "generator_tool.hpp"
#include "stream_tool.hpp"

#include <iostream>
using std::cout;
using std::endl;
void test_004(){
    vector<int> num1 = {1, 2};
    vector<int> num2 = {3, 4};
    cout<<num1<<endl;
    cout<<num2<<endl;
    double ret = findMedianSortedArrays(num1, num2);
    cout<<ret<<endl;
}