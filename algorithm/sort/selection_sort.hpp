#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP


/*
 * @brief 选择排序和冒泡排序类似，冒泡排序通过交换两个逆序的元素来找到当前子序列最大的值，而选择排序则直接通过遍历寻找最大的值，然后交换位置
 */
void selection_sort(int *start, int* end, bool(*less)(int, int )){
    for(int* i = start;i < end;i ++){
        int* max_ptr = start;
        for(int* j = start;j < end - (i - start);j ++){
            if(less(*max_ptr, *j)){
                max_ptr = j;
            }
        }

        int tmp = *max_ptr;
        *max_ptr = *(end - (i - start) - 1);
        *(end - (i - start) - 1) = tmp;
    }
}


#endif