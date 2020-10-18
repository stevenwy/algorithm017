/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_preorder_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 19时15分38秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// https://leetcode-cn.com/problems/binary-tree-preorder-traversal/

// 1. Recursive solution    根->左->右
class Solution {
public:
    vector<int> result;
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) return result;
        result.push_back(root->val);
        if (root->left != nullptr) preorderTraversal(root->left);
        if (root->right != nullptr) preorderTraversal(root->right);
        return result;
    }
};

// 2. Iterative solution
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> stack;
        stack.push(root);
        while (!stack.empty()) {
            TreeNode* cur = stack.top();
            stack.pop();
            result.push_back(cur->val);
            // 注意先右子树，后左子树
            if (cur->right != nullptr) stack.push(cur->right);
            if (cur->left != nullptr) stack.push(cur->left);
        }
        return result;
    }
};
