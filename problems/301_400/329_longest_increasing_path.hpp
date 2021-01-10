#include <vector>


using std::vector;

int max(int a, int b){
    return a > b? a : b;
}

/*
 * @brief 矩阵中的最长递增路径
 * @note  使用递归暴力破解，通过使用visited数组将已经访问过的点的最长路径记录下来防止重复访问
 */
int longest_inc_path(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &visited){
    if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[0].size()){
        return 0;
    }

    if(visited[i][j] != 0)
        return visited[i][j];

    int ret = 0;
    if(i != 0 && matrix[i - 1][j] > matrix[i][j]){
        ret = max(ret, longest_inc_path(matrix, i - 1, j, visited));
    }

    if(i != matrix.size() - 1 && matrix[i + 1][j] > matrix[i][j]){
        ret = max(ret, longest_inc_path(matrix, i + 1, j, visited));
    }

    if(j != 0 && matrix[i][j - 1] > matrix[i][j]){
        ret = max(ret, longest_inc_path(matrix, i, j - 1, visited));
    }

    if(j != matrix[0].size() - 1 && matrix[i][j + 1] > matrix[i][j]){
        ret = max(ret, longest_inc_path(matrix, i, j + 1, visited));
    }

    visited[i][j] = ret + 1;
    return visited[i][j];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    int ret = 0;
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), 0));
    for(int i = 0;i < matrix.size();i ++){
        for(int j = 0;j < matrix[0].size();j ++){
            if(visited[i][j] != 0)
                ret = max(ret, visited[i][j]);
            else
                ret = max(ret, longest_inc_path(matrix, i, j, visited));
        }
    }

    return ret;
}

#include "ios_include.hpp"

void test_329(){
    vector<vector<int>> vec = {{9,9,4}, {6,6,8}, {2,1,1}};
    vector<vector<int>> vec2 = {{3,4,5}, {3,2,6}, {2,2,1}};
    int ret = longestIncreasingPath(vec);
    cout<<ret<<endl;
}