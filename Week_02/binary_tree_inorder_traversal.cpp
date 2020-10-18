/*
 * =====================================================================================
 *
 *       Filename:  binary_tree_inorder_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 18时16分42秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// https://leetcode-cn.com/problems/binary-tree-inorder-traversal/

// 1. Recursion : inorder 左->根->右
class Solution {
    public:
    vector<int> rvector;
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return rvector;
        if (root->left != nullptr) inorderTraversal(root->left);
        rvector.push_back(root->val);
        if (root->right != nullptr) inorderTraversal(root->right);
        return rvector;
    }
};

// 2. Iteration
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<TreeNode*> stack;
        while (root || !stack.empty()) {
            // 找到最左下的叶子节点
            while (root) {
                stack.push(root);
                root = root->left;
            }
            // 处理根节点
            root = stack.top();
            stack.pop();
            result.push_back(root->val);
            // 处理右子树
            root = root->right;
        }
        return result;
    }
};
