/*
 * =====================================================================================
 *
 *       Filename:  search_in_rotated_sorted_array.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时39分53秒
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
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) return mid;
            if (nums[l] <= nums[mid]) {  // 左半部分单调递增
                if (target >= nums[l] && target < nums[mid]) r = mid - 1;   // 在[l, mid)区间
                else l = mid + 1;   // 在(mid, r]区间
            } else {    // 右半部分单调递增
                if (target > nums[mid] && target <= nums[r]) l = mid + 1;   // 在(mid, r]区间
                else r = mid - 1;   // 在[l, mid)区间
            }
        }
        return -1;
    }
};
