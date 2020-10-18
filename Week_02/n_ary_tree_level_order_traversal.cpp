/*
 * =====================================================================================
 *
 *       Filename:  n_ary_tree_level_order_traversal.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 19时17分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal/

/* 1. iterative solution
 * 这里需要借助queue，每一层的节点从队尾入队，输出结果时则从队首取
 */
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if (root == nullptr) return result;

        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            // 因为队列的size一直在变化，所以要保存当前层的队列大小
            int size = q.size();
            vector<int> curLevel;
            for (int i = 0; i < size; i++) {
                Node* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                // root为level 0层，把root的所有儿子放在队列里，即可得到level 1层的全部节点，依次循环下去，就可以得到level 2层...level n层的所有节点
                for (auto child : cur->children)
                    q.push(child);
            }
            // 此处已经有了每一层的结果vector
            result.push_back(curLevel);
        }
        return result;
    }
};
