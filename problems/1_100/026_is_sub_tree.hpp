#include "ios_include.hpp"

bool is_sub_tree(TreeNode* A, TreeNode* B){
        if(!B) return true;
        if(!A) return false;
        if(A->val == B->val){
            return is_sub_tree(A->left, B->left) && is_sub_tree(A->right, B->right);
        }

        return false;
    }

bool isSubStructure(TreeNode* A, TreeNode* B) {
    if(!A || !B)
        return false;

    bool ret = false;
    if(A->val == B->val){
        ret = is_sub_tree(A, B);
    }

    if(!ret) 
        ret = isSubStructure(A->left, B);

    if(!ret) 
        ret = isSubStructure(A->right, B);
    return ret;
    }