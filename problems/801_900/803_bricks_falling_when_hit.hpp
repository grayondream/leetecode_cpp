#include "ios_include.hpp"

/*
 * @brief 顶部的砖块和标记为2的砖块是稳定砖块
 */
bool is_stable(vector<vector<int>> &grid, const int &x, const int &y) {
    int row = grid.size();
    int col = grid[0].size();
    if (x == 0)
        return true;

    if (x + 1 < row && grid[x + 1][y] == 2)
        return true;
    if (x - 1 >= 0 && grid[x - 1][y] == 2)
        return true;
    if (y + 1 < col && grid[x][y + 1] == 2)
        return true;
    if (y - 1 >= 0 && grid[x][y - 1] == 2)
        return true;

    return false;
}

int dfs(vector<vector<int>> &grid, int x, int y) {
    int row = grid.size();
    int col = grid[0].size();
    if (x < 0 || y < 0 || x >= row || x >= col || grid[x][y] != 1)
        return 0;

    int ret = 0;
    grid[x][y] = 2;
    ret = 1 + dfs(grid, x + 1, y) + dfs(grid, x - 1, y) + dfs(grid, x, y - 1) + dfs(grid, x, y + 1);
    return ret;
}

/*
 * @brief 有一个 m x n 的二元网格，其中 1 表示砖块，0 表示空白。砖块 稳定（不会掉落）的前提是:
 * 一块砖直接连接到网格的顶部，或者至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时, 给你一个数组 hits
 * ，这是需要依次消除砖块的位置。每当消除 hits[i] =
 * (rowi,coli)位置上的砖块时，对应位置的砖块（若存在）会消失，然后其他的砖块可能因为这一消除操作而掉落。一旦砖块掉落，它会立即从网格中消失（即，它不会落在其他稳定的砖块上）
 */
vector<int> hitBricks(vector<vector<int>> &grid, vector<vector<int>> &hits) {
    int row = grid.size();
    int col = grid[0].size();
    int len = hits.size();
    for (auto ele : hits) {
        grid[ele[0]][ele[1]] -= 1;
    }

    for (int i = 0; i < col; i++) {
        dfs(grid, 0, i);
    }

    vector<int> ret = vector<int>(len, -1);
    for (int i = len - 1; i >= 0; i--) {
        int x = hits[i][0], y = hits[i][1];
        grid[x][y] += 1;
        if (!is_stable(grid, x, y) || 0 == grid[x][y]) {
            ret[i] = 0;
        } else {
            ret[i] = dfs(grid, x, y) - 1;
        }
    }

    return ret;
}

void test_803() {
    vector<vector<int>> grid = {{1}, {1}, {1}, {1}, {1}};
    vector<vector<int>> hits = {{3, 0}, {4, 0}, {1, 0}, {2, 0}, {0, 0}};
    vector<int> ret = hitBricks(grid, hits);
    cout << ret << endl;
}