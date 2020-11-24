/*
 * =====================================================================================
 *
 *       Filename:  jump_game.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时39分12秒
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
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > reachable) return false; // 如果当前下标已经超出了可以达到的位置，则无法到达终点
            reachable = max(reachable, i + nums[i]);    // max记录最远能到达的位置
        }
        return true;
    }
};

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachable = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (reachable >= i && reachable < i + nums[i]) reachable = i + nums[i];
        }
        return reachable >= nums.size() - 1;
    }
};
