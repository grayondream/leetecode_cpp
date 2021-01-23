#include "ios_include.hpp"

class uset {
public:
    uset(int n) {
        cnt = n;
        for (int i = 0; i < n; i++) {
            roots.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int x) { return x == roots[x] ? roots[x] : roots[x] = find(roots[x]); }

    bool unite(int rst, int snd) {
        int root_rst = find(rst);
        int root_snd = find(snd);
        if (root_rst == root_snd) {
            return false;
        }

        if (rank[root_rst] < rank[root_snd]) {
            swap(root_rst, root_snd);
        }

        roots[root_snd] = root_rst;
        rank[root_rst] += rank[root_snd];
        cnt--;
        return true;
    }

    int get_count() { return cnt; }

private:
    vector<int> roots;
    vector<int> rank;
    int cnt;
};

/*
 * @brief 联通区域相关的问题直接使用并查集
 */
int makeConnected(int n, vector<vector<int>> &connections) {
    int len = connections.size();
    if (len < n - 1) { //边数目不够
        return -1;
    }

    uset us(len);
    for (int i = 0; i < len; i++) {
        us.unite(connections[i][0], connections[i][1]);
    }

    return us.get_count() - 1;
}