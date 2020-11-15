/*
 * =====================================================================================
 *
 *       Filename:  construct_binary_tree_from_preorder_and_inorder_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/15 14时16分39秒
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
class Solution {
private:
    int getIndex(vector<int>& vector, int element) {
        int res;
        auto it = find(vector.begin(), vector.end(), element);
        if (it != vector.end())
            res = distance(vector.begin(), it);
        else
            res =  -1;
        return res;
    }
    // divide & conquer
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int cur, int left, int right) {
        // recursion terminator
        if (cur > preorder.size() - 1 || left > right) return NULL;
        // prepare data
        TreeNode *root = new TreeNode(preorder[cur]);
        int rootIndex = getIndex(inorder, preorder[cur]);
        // split problem
        // lsub = [l, rootIndex - 1];
        // rsub = [rootIndex + 1, inorder.size() - 1];
        // drill down
        root->left = _buildTree(preorder, inorder, cur + 1, left, rootIndex - 1);
        // 这边的关键逻辑是从pre-order数组里面计算出右子树的下标，cur + 左子树的数量（root - left）再+1则为右子树的root
        root->right = _buildTree(preorder, inorder, cur + rootIndex - left + 1, rootIndex + 1, right);
        // reverse if needed
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *root = _buildTree(preorder, inorder, 0, 0, inorder.size() - 1);
        return root;
    }
};
