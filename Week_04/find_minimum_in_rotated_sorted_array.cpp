/*
 * =====================================================================================
 *
 *       Filename:  find_minimum_in_rotated_sorted_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时41分08秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// 1. 暴力法，双指针i, j，找到 *i > *j的地方，*j指向的即为最小值
// 2. 二分查找
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            if (nums[l] <= nums[r]) return nums[l];
            int mid = l + (r - l) / 2;
            if (nums[l] <= nums[mid]) l = mid + 1;
            else r = mid;
        }
        return -1;
    }
};
