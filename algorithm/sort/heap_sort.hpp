#ifndef HEAP_SORT_HPP
#define HEAP_SORT_HPP

void heap_adjust(int *start, int *end, int *idx, bool (*less)(int, int)){
    int *left = start + 2 * (idx - start) + 1;
    int *right = start + 2 * (idx - start) + 2;
    int *largest = idx;
    if(left < end && less(*largest, *left)){
        largest = left;
    }

    if(right < end && less(*largest, *right)){
        largest = right;
    }

    if(largest != idx){
        int tmp = *idx;
        *idx = *largest;
        *largest = tmp;

        heap_adjust(start, end, largest, less);
    }
}

void make_heap(int *start, int *end, bool (*less)(int, int)){
    int len = end - start;
    for(int *i = start + len / 2 - 1;i >= start;i--){
        heap_adjust(start, end, i, less);   
    }
}

void heap_sort(int *start, int *end, bool (*less)(int, int)){
    make_heap(start, end, less);
    for(int *i = end - 1;i >= start;i --){
        int tmp = *i;
        *i = *start;
        *start = tmp;

        heap_adjust(start, i, start, less);
    }
}

#endif