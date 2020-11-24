/*
 * =====================================================================================
 *
 *       Filename:  jump_game_ii.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时43分15秒
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
    int jump(vector<int>& nums) {
        int res = 0;
        int maxReach = 0;
        int curPos = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);  // 遍历下一步的几个候选中，最远能达到的距离
            if (i == curPos) {    // 已经到达最远的位置，step + 1，准备选择下一步最远的步数
                curPos = maxReach;
                res++;
            }
        }
        return res;
    }
};
