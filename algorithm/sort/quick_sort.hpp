#ifndef QUICK_SORT_HPP
#define QUICK_SORT_HPP

/*
 * @brief 这里简单的采用最左边的元素作为哨兵
 */
int* parition(int *start, int *end, bool(*less)(int, int)){
    int povit = *start;
    end = end - 1;
    while(start < end){
        while(end > start && less(povit, *end)){
            end--;
        }

        *start = *end;
        while(start < end && less(*start, povit)){
            start++;
        }
        *end = *start;
    }

    *start = povit;
    return start;
}

/*
 * @brief 快速排序通过通过哨兵将一个序列划分为两个子序列，左边的序列小于哨兵，右边的序列大于哨兵，所以出现一个问题如何选择适当的哨兵使得划分尽可能的保障二分，最好的方式是使用中位数，但是得不偿失，因此可能的办法是从中随机选取三个值，取三个值的中位数
 * @note 最好性能O(nlogn)，最差性能O(n*n)
 */
void quick_sort(int *start, int *end, bool (*less)(int, int)){
    if((end - start) > 1){
        int* povit = parition(start, end, less);
        quick_sort(start, povit, less);
        quick_sort(povit + 1, end, less);
    }
}

#endif