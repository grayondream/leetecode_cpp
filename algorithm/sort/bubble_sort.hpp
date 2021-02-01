#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

/*
 * @brief 最简单的冒泡排序算法，排序的范围采用[start, end)，并且函数接受一个额外的函数指针可以用来指定进行比较的函数
 * @note 时间复杂度O(n*n)
 */
void bubble_sort(int *start, int *end, bool (*less)(int, int)){
    for(int *i = start;i < end;i ++){
        for(int *j = start + 1;j < end - (i - start);j ++){
            if(less(*j, *(j - 1))){
                int tmp = *j;
                *j = *(j - 1);
                *(j - 1) = tmp;                
            }
        }
    }
}


#endif