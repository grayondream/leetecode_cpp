#pragma once
#ifndef __LECODE_USET_HPP__
#define __LECODE_USET_HPP__

#include <vector>

using std::swap;
using std::vector;

namespace lecode {
class uset {
public:
    uset(int n) {
        for (int i = 0; i < n; i++) {
            roots.push_back(i);
            rank.push_back(1);
        }
    }

    int find(const int id) {
        if (id != roots[id]) {
            roots[id] = find(roots[id]);
        }

        return roots[id];
    }

    bool merge(const int &rst, const int &snd) {
        int root1 = find(rst);
        int root2 = find(snd);
        if (root1 == root2)
            return false;

        if (rank[root1] < rank[root2])
            swap(root1, root2);

        //将大分支链接到小分支上
        roots[root2] = root1;
        rank[root1] += rank[root2];
        return false;
    }

    vector<int> get_roots() const { return roots; }

private:
    vector<int> rank;
    vector<int> roots;
};
} // namespace lecode
// namespace uset
#endif