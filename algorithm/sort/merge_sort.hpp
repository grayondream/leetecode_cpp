#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <stdlib.h>
#include <memory.h>

void merge(int *start, int *mid, int *end, bool (*less)(int, int)){
    int len = end - start;
    int *tmp = new int[len];
    memcpy(tmp, start, len * sizeof(int));
    int *idx1 = tmp;
    int *idx2 = tmp + (mid - start);
    int *idx3 = start;
    while(idx1 < tmp + (mid - start) && idx2 < tmp + len){
        if(less(*idx1, *idx2)){
            *idx3 = *idx1;
            idx1++;
        }else{
            *idx3 = *idx2;
            idx2 ++;
        }

        idx3++;
    }

    while(idx1 < tmp + (mid - start)){
        *idx3 ++ = *idx1++;
    }

    while(idx2 < tmp + len){
        *idx3 ++ = *idx2++;
    }
    
    if(tmp)
        delete [] tmp;

    tmp = nullptr;
}

void merge_sort(int *start, int *end, bool (*less)(int, int)){
    if(end - start > 1){
        int* mid = start + (end - start) / 2;
        merge_sort(start, mid, less);
        merge_sort(mid, end, less);
        merge(start, mid, end, less);
    }
}

#endif