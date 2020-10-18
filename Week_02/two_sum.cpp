/*
 * =====================================================================================
 *
 *       Filename:  two_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/10/18 18时00分05秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

//https://leetcode-cn.com/problems/two-sum/description/


// 1. brute force

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] + nums[i] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    break;
                }
            }
        }
        return result;
    }
};

/* 2. HashMap
 * 常规思路：暴力法中需要用一次数组的遍历去寻找（target - nums[i])，利用hashmap可以将这次循环的O(N)降为O(1)
 * hashmap对nums[i]的值去做散列，value则为数组中对应的index，hashmap(nums[i], i)
 * hashmap原本需要两次循环，第一次先创建hashmap，第二次去匹配结果
 * 但是结果的nums[i]和target-nums[i]是成对出现的，[index1, index2]与[index2, index1]是等价的
 * 所以一次循环即可解决
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;    // hashTable<nums[i], i> 以当前的值为key去做散列，数组中的index为value
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (table.find(target - nums[i]) != table.end()) {
                result.push_back(table[target - nums[i]]);
                result.push_back(i);
                break;
            }
            table.insert({nums[i], i});
        }
        return result;
    }
};






