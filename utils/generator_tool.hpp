
#include <iterator>
#include <random>
#include <algorithm>
#include <ctime>

using std::back_inserter;
using std::default_random_engine;
using std::uniform_int_distribution;
using std::sort;

/*
 * @brief 容器生成相关内容的工具函数
 */


template<class Container>
Container generate_container(size_t len, int min_border = 0, int max_border = 100, bool sorted=false){
    default_random_engine rand(time(NULL));
    uniform_int_distribution<int> urand(min_border, max_border);
    Container con;
    for(int i =0;i < len;i ++){
        *(back_inserter(con)) = urand(rand);
    }

    if(sorted){
        sort(con.begin(), con.end());
    }
    return con;
}