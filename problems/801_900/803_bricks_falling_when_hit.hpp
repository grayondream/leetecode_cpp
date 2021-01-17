#include "ios_include.hpp"

class uset {
public:
    uset(int n) : parent(n), rank(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x) {
        if (x == parent[x]) {
            return x;
        }

        parent[x] = find(parent[x]);
        return parent[x];
    }

    void merge(int node1, int node2) {
        int parent1 = find(node1);
        int parent2 = find(node2);
        if (parent1 == parent2)
            return;

        parent[parent1] = parent2;
        rank[parent2] += rank[parent1];
    }

    int size(int x) { return rank[find(x)]; }

private:
    vector<int> parent;
    vector<int> rank;
};

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
    uset us(row * col + 1);
    vector<vector<int>> status = grid;
    //将打掉的砖块的状态转换成打掉之后的状态
    for (int i = 0; i < len; i++) {
        status[hits[i][0]][hits[i][1]] = 0;
    }

    //遍历每一个结点创建打掉砖块之后的并查集
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (1 == status[i][j]) {
                if (0 == i) { //顶部的节点是稳定的直接和col * row连接，col*row表示稳定点，每个点编码为i * col + j
                    us.merge(col * row, i * col + j);
                }
                //将当前节点和上侧节点进行加入到并查集中同一个连通区域内
                if (i > 0 && status[i - 1][j] == 1) {
                    us.merge(i * col + j, (i - 1) * col + j);
                }

                //将当前节点和左侧节点加入到并查集的同一个连通区域
                if (j > 0 && status[i][j - 1] == 1) {
                    us.merge(i * col + j, i * col + j - 1);
                }
            }
        }
    }

    const vector<pair<int, int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> ret(len, 0);
    for (int i = len - 1; i >= 0; i--) {
        int x = hits[i][0];
        int y = hits[i][1];
        if (grid[x][y] == 0) { //节点没有砖块
            continue;
        }

        //当前稳定的砖块数量
        int pre = us.size(col * row);
        if (x == 0) {
            us.merge(y, row * col);
        }

        //遍历右，下，左，上四个方向的结点，反向添加砖块，将当前砖块周围存在的砖块连接
        for (const auto dir : dirs) {
            int cx = x + dir.first;
            int cy = y + dir.second;
            if (cx >= 0 && cx < row && cy >= 0 && cy < col) {
                if (status[cx][cy] == 1) {
                    us.merge(x * col + y, cx * col + cy);
                }
            }
        }

        int sz = us.size(col * row);
        ret[i] = max(0, sz - pre - 1);
        status[x][y] = 1;
    }

    return ret;
}

void test_803() {
    vector<vector<int>> grid = {{1}, {1}, {1}, {1}, {1}};
    vector<vector<int>> hits = {{3, 0}, {4, 0}, {1, 0}, {2, 0}, {0, 0}};
    cout << grid.size() << grid[0].size() << endl;
    cout << grid << endl;
    vector<int> ret = hitBricks(grid, hits);
    cout << ret << endl;
}