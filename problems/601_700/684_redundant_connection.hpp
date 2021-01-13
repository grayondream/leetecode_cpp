#include "ios_include.hpp"

class unset{
public:
    unset(int n) : parent(vector<int>(n, 0)), depth(vector<int>(n, 0)){
        for(int i = 0;i < n;i ++){
            parent[i] = i;
        }
    }

    bool merge(int node1, int node2){
        int node1_parent = find(node1);
        int node2_parent = find(node2);
        if(node1_parent == node2_parent){           //两个节点已经在同一个连通图中，如果再连接则会出现环
            return true;
        }

        if(depth[node1_parent] < depth[node2_parent]){
            swap(node1_parent, node2_parent);
        }

        parent[node2_parent] = node1_parent;
        if(depth[node1_parent] == node2_parent){
            depth[node1_parent] ++;
        }

        return false;
    }

    int find(int x){
        if(x != parent[x])
            parent[x] = find(parent[x]);

        return parent[x];
    }

private:
    vector<int> parent;         //每个节点的父节点  
    vector<int> depth;          //当前连通图的深度，用于优化并查集的深度，在合并时始终将大节点合并到小节点上
};


/*
 * @brief 对于拥有n个节点的树，其边应该有n-1条，而给定的图有n条边，如何找到多余的边，去除该边使得图称为一棵树
 * @note  多余的边去掉整个图仍然是一个联通区域，利用这个特性寻找多余的边
 */
vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    unset s(edges.size());
    for(auto edge : edges){
        //-1是因为并查集中的下标从0开始，而此处是从1开始计算
        if(s.merge(edge[0] - 1, edge[1] - 1)){
            return {edge[0], edge[1]};
        }
    }

    return {};
}