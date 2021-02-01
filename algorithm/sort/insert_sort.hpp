#ifndef INSERT_SORT_HPP
#define INSERT_SORT_HPP

#include <stdlib.h>
#include <memory.h>

/*
 * @brief 插入排序算法的基本规则和打扑克牌类似，从当前位置向前遍历寻找当前元素适合插入的位置
 * @note 时间复杂度O(n*n)，优势是如果元素部分有序则不需要对有序的部分进行操作，一般用于规模比较小大部分有序的序列中
 */
void insert_sort(int *start, int *end, bool(*less)(int, int)){
    for(int *i = start;i < end;i ++){
        int val = *i;
        int *j = i;
        while(j > start && less(val, *(j - 1))){
            *j = *(j - 1);
            j--;
        }

        *j = val;
    }
}

/*
 * @brief 插入排序的另一种高效的实现方式是仅仅通过嵌套的内循环找到需要插入的位置然后将整块内存进行移动
 */
void insert_sort_mem(int *start, int *end, bool(*less)(int, int)){
    for(int *i = start;i < end;i ++){
        int val = *i;
        int *j = i;
        while(j > start && less(val, *(j - 1))){
            j--;
        }

        memmove(j + 1, j, sizeof(int) * (i - j));
        *j = val;
    }
}

#endif