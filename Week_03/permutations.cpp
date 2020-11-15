/*
 * =====================================================================================
 *
 *       Filename:  permutations.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/15 14时30分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Solution {
public:
    void _permute(vector<vector<int>> &res, vector<int> &nums, vector<int> &permutation) {
        // terminator
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        // process current logic
        for (int i = 0; i < nums.size(); i++) {
            bool is_contained = false;
            for (int j = 0; j < permutation.size(); j++) {
                if (permutation[j] == nums[i]) {
                    is_contained = true;
                    break;
                }
            }
            if (is_contained) continue;
            permutation.push_back(nums[i]);
            // drill down
            _permute(res, nums, permutation);
            // reverse state if needed, permutation is passed by reference, we should reverse the state
            permutation.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() == 0) return res;

        vector<int> permutation;
        _permute(res, nums, permutation);
        return res;
    }
};
