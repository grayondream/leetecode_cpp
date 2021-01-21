#include "ios_include.hpp"

class UnionFind {
public:
    vector<int> parent;
    vector<int> size;
    int n;
    // 当前连通分量数目
    int setCount;

public:
    UnionFind(int _n) : n(_n), setCount(_n), parent(_n), size(_n, 1) { iota(parent.begin(), parent.end(), 0); }

    int findset(int x) { return parent[x] == x ? x : parent[x] = findset(parent[x]); }

    bool unite(int x, int y) {
        x = findset(x);
        y = findset(y);
        if (x == y) {
            return false;
        }
        if (size[x] < size[y]) {
            swap(x, y);
        }
        parent[y] = x;
        size[x] += size[y];
        --setCount;
        return true;
    }

    bool connected(int x, int y) {
        x = findset(x);
        y = findset(y);
        return x == y;
    }
};

/*
 * @brief 给定图边，返回图中最小生成树的关键边和伪关键边
 * @note 可以暴力枚举，找出所有的最小生成树，然后找出公共边和伪关键边
 */
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges) {
    int edage_sz = edges.size();
    //將编号插入到每条边中
    for (int i = 0; i < edage_sz; i++) {
        edges[i].push_back(i);
    }

    //根据权重排序
    sort(edges.begin(), edges.end(), [](const auto &rst, const auto &snd) { return rst[2] < snd[2]; });
    UnionFind us(n);
    int value = 0;
    for (int i = 0; i < edage_sz; i++) {
        if (us.unite(edges[i][0], edges[i][1])) { //根据边信息按照权重的从大到小将节点连接
            value += edges[i][2];
        }
    }

    vector<vector<int>> ret(2);
    for (int i = 0; i < edage_sz; i++) {
        UnionFind uf(n);
        int val = 0;
        //判断关键边
        for (int j = 0; j < edage_sz; j++) {
            if (i != j && uf.unite(edges[j][0], edges[j][1])) { //不包含第i条边时进行最小生成树的构造
                val += edges[j][2];
            }
        }

        if (uf.setCount != 1 || (uf.setCount == 1 && val > value)) { //最小生成树不存在或者存在最小生成树且树的权重大于去掉边之前
            ret[0].push_back(edges[i][3]);
            continue;
        }

        //判断是否为伪关键边
        uf = UnionFind(n);
        uf.unite(edges[i][0], edges[i][1]);
        val = edges[i][2];
        for (int j = 0; j < edage_sz; j++) {
            if (i != j && uf.unite(edges[j][0], edges[j][1])) { //不包含第i条边时进行最小生成树的构造
                val += edges[j][2];
            }
        }

        if (val == value) { //存在包含当前边的最小生成树且当前边不是关键边则是伪关键边
            ret[1].push_back(edges[i][3]);
        }
    }

    return ret;
}