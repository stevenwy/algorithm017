/*
 * =====================================================================================
 *
 *       Filename:  lowest_common_ancestor_of_a_binary_tree.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/15 14时14分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

 /* 思路：根据LCA的定义和题目的说明，p、q都是唯一的，且p、q都在给定的二叉树中
  * 直观上，分为两种情况：
  * 1. 如果p、q分别在root节点的左右子树中，则root则为LCA
  * 2. 如果p、q在root节点的同一边，则首先遍历到的那个则为LCA
  */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return left ? left : right;
    }
};
