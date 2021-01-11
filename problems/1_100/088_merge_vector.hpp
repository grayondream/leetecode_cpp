#include "ios_include.hpp"

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    const int len = nums1.size();
    int i = m - 1;
    int j = n - 1;
    int k = len - 1;
    for(;i >= 0 && j >= 0; ){
        if(nums1[i] > nums2[j]){
            nums1[k--] = nums1[i--];
        }else{
            nums1[k--] = nums2[j--];
        }
    }

    while(i >= 0){
        nums1[k--] = nums1[i--];
    }

    while(j >= 0){
        nums1[k--] = nums2[j--];
    }
}