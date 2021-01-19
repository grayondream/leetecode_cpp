
#pragma once
#ifndef __LECODE_TREE_HPP__
#define __LECODE_TREE_HPP__

namespace lecode {
class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}

public:
};

} // namespace lecode
#endif