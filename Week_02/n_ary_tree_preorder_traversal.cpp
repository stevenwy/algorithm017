/*
 * =====================================================================================
 *
 *       Filename:  n_ary_tree_preorder_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 18时06分00秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// https://leetcode-cn.com/problems/n-ary-tree-preorder-traversal

// 1. Recursive preorder : root -> children
class Solution {
public:
    vector<int> result;
public:
    vector<int> preorder(Node* root) {
        if (root == nullptr) return result;
        result.push_back(root->val);
        for (Node* child : root->children)
                preorder(child);
        return result;
    }
};

// 2. Iteration : preorder traversal
// 用stack模拟递归的过程
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> result;
        if (root == nullptr) return result;

        stack<Node*> stack;
        stack.push(root);
        while (!stack.empty()) {
            Node* cur = stack.top();
            stack.pop();
            result.push_back(cur->val);
            // 此处的child入栈要注意，下标从size()-1递减到0
            for (int i = cur->children.size() - 1; i >= 0; i--) {
                if (cur->children[i] != nullptr)
                    stack.push(cur->children[i]);
            }
        }
        return result;
    }
};
