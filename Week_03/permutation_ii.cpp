/*
 * =====================================================================================
 *
 *       Filename:  permutation_ii.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/15 14时30分52秒
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

    void _permutation(vector<int>& nums, vector<int>& permutation, vector<bool>& used) {
        if (permutation.size() == nums.size()) {
            res.push_back(permutation);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i]) continue;
            // 去重逻辑：因为是已经排过序的nums，从nums取元素要保证nums当前要排列的元素跟前面一个不能相同，
            // 且used容器表示的是横向的决策树
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) {
                continue;
            }
            permutation.push_back(nums[i]);
            used[i] = true;
            _permutation(nums, permutation, used);
            permutation.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) return res;

        sort(nums.begin(), nums.end());
        vector<int> permutation;
        vector<bool> used(nums.size(), false);
        _permutation(nums, permutation, used);
        return res;
    }
};
