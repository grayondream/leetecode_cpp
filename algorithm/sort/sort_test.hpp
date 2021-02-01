#include <iostream>
#include <ctime>
#include <cstdlib>
#include "bubble_sort.hpp"
#include "selection_sort.hpp"
#include "insert_sort.hpp"
#include "merge_sort.hpp"
#include "quick_sort.hpp"
#include "heap_sort.hpp"

using std::cout;
using std::endl;

void generate_rand_list(int *arr, int len, int limit = 100){
    
    for(int i = 0;i < len;i ++){
        arr[i] = rand() % limit;
    }
}

void print_list(int *arr, int len){
    for(int i = 0;i < len;i ++){
        cout<<arr[i]<<" ";
    }

    cout<<endl;
}

bool less_than(int rst, int snd){
    return rst <= snd;
}

int test_sort(){
    int len = 100000;
    int *ptr = new int[len];
    srand( (unsigned)time( NULL ) ); 
    typedef void (*sort_func)(int*, int *, bool(*)(int,int));
    sort_func funcs[] = {bubble_sort, selection_sort, insert_sort, insert_sort_mem, merge_sort, quick_sort, heap_sort};
    for(int i = 0;i < sizeof(funcs) / sizeof(funcs[0]);i ++){
        cout<<"before sorted: "<<endl;
        generate_rand_list(ptr, len);
        if(len < 20)
            print_list(ptr, len);

        cout<<"after sorted: "<<endl;
        clock_t start = clock();
        funcs[i](ptr, ptr + len, less_than);
        clock_t end = clock();
        double cost = double(end-start)/CLOCKS_PER_SEC;
        if(len < 20)
            print_list(ptr, len);

        cout<<"cost time:"<<cost<<endl;
        cout<<endl;
    }
    
    if(ptr)
        delete ptr;
    
    ptr = nullptr;
}