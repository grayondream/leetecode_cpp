#include "ios_include.hpp"

class unset {
public:
    unset(int n) {
        for (int i = 0; i < n; i++) {
            roots.push_back(i);
            rank.push_back(1);
        }
    }

    int find(int node) {
        while (node != roots[node]) {
            roots[node] = roots[roots[node]];
            node = roots[node];
        }

        return node;
    }

    bool merge(int node1, int node2) {
        int node1_root = find(node1);
        int node2_root = find(node2);
        if (node1_root == node2_root) {
            return false;
        }

        if (rank[node1_root] < rank[node2_root]) {
            roots[node2_root] = node1_root;
            rank[node1_root] += rank[node2_root];
        } else {
            roots[node1_root] = node2_root;
            rank[node2_root] += rank[node1_root];
        }

        return true;
    }

public:
    vector<int> roots;
    vector<int> rank;
};

vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int len = accounts.size();
    unset us(len);
    unordered_map<string, int> id_map;
    //遍历每一个邮件，建立对应于每个邮件和当前下标的关系图，有重复出现邮件的条目会合并，即在同一个联通区域内
    for (int i = 0; i < len; i++) {
        int email_sz = accounts[i].size();
        for (int j = 1; j < email_sz; j++) {
            if (id_map.find(accounts[i][j]) != id_map.end()) {
                int root = id_map[accounts[i][j]];
                us.merge(root, us.roots[i]);
            } else {
                id_map[accounts[i][j]] = i;
            }
        }
    }

    //根据并查集的连通图，建立索引和邮件列表的映射
    unordered_map<int, unordered_set<string>> dump;
    for (int i = 0; i < len; i++) {
        int root = us.find(i);
        int email_sz = accounts[i].size();
        for (int j = 1; j < email_sz; j++) {
            dump[root].insert(accounts[i][j]);
        }
    }

    //根据上面的映射还原最终的邮件列表
    vector<vector<string>> ret;
    for (auto node : dump) {
        vector<string> ret_tmp;
        int root = node.first;
        string name = accounts[root][0];
        ret_tmp.push_back(name);
        for (auto item : node.second) {
            ret_tmp.push_back(item);
        }

        sort(ret_tmp.begin(), ret_tmp.end());
        ret.push_back(ret_tmp);
    }

    return ret;
}