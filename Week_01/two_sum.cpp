/*
 * =====================================================================================
 *
 *       Filename:  two_sum.cpp
 *
 *    Description: LeetCode NO.1 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时37分35秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

/* Solution: 
    insert the input array into hashmap    hashmap<nums[i], i>
    with only one pass, we can find the result
*/

// 因为C语言的std library没有hashmap，所以该题该用cpp来解决
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result;
        
        for (int i = 0; i < nums.size(); ++i) {
            int resultNum = target - nums[i];
            if (hashMap.find(resultNum) != hashMap.end()) {
                result.push_back(hashMap[resultNum]);
                result.push_back(i);
                return result;
            }
            hashMap[nums[i]] = i;
        }
        return result;
    }
};
