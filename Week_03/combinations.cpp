/*
 * =====================================================================================
 *
 *       Filename:  combinations.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/15 14时17分32秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
private:
    vector<vector<int>> res;

    void _combine(int n, int k, int begin, vector<int>& combination) {
        if (combination.size() == k) {
            res.push_back(combination);
            return;
        }
        
        for (int i = begin; i <= n - k + combination.size() + 1; i++) {
            combination.push_back(i);
            _combine(n, k, i + 1, combination);
            combination.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        if (n < k || k <= 0) return res;

        vector<int> combination;
        _combine(n, k, 1, combination);
        return res;
    }
};
