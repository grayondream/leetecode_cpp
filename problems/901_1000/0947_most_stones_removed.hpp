#include "ios_include.hpp"

class unset {
public:
    unset(int n) : parent(vector<int>(n, 0)), depth(vector<int>(n, 0)) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    bool merge(int node1, int node2) {
        int node1_parent = find(node1);
        int node2_parent = find(node2);
        if (node1_parent == node2_parent) { //两个节点已经在同一个连通图中，如果再连接则会出现环
            return false;
        }

        if (depth[node1_parent] < depth[node2_parent]) {
            swap(node1_parent, node2_parent);
        }

        parent[node2_parent] = node1_parent;
        if (depth[node1_parent] == depth[node2_parent]) {
            depth[node1_parent]++;
        }

        return true;
    }

    int find(int x) {
        if (x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

private:
    vector<int> parent; //每个节点的父节点
    vector<int> depth;  //当前连通图的深度，用于优化并查集的深度，在合并时始终将大节点合并到小节点上
};
/*
 * @brief 给定石头所在的位置，尝试如果有多个石头在同一行或者同一列则删除至同一列或者同一行只有一个石头为止
 * @note 如果将每个石头的位置看作一个顶点那就是连通区域数量的问题，使用并查集解决比较方便
 */
int removeStones(vector<vector<int>> &stones) {
    unordered_map<int, int> row;
    unordered_map<int, int> col;
    int len = stones.size();
    int ret = 0;
    unset dsu(len);
    for (int i = 0; i < len; i++) {
        int x = stones[i][0], y = stones[i][1];
        if (row.find(x) != row.end()) {
            ret += dsu.merge(i, row[x]);
        }

        row[x] = i;
        if (col.find(y) != col.end()) {
            ret += dsu.merge(i, col[y]);
        }
        col[y] = i;
    }

    return ret;
}