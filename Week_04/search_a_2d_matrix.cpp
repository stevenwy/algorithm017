/*
 * =====================================================================================
 *
 *       Filename:  search_a_2d_matrix.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  2020/11/24 20时40分17秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// 1. 先转化成一维的数组，然后在升序数组上进行二分查找   忽略
// 2. 直接二分查找，先判断出在哪一行，然后再判断距离哪一列

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;
        int col_num = matrix[0].size();
        int row = 0, col = 0;
        
        int top = 0, down = matrix.size() - 1;
        while (top <= down) {
            int mid = top + (down - top) / 2;
            if (target >= matrix[mid][0] && target <= matrix[mid][col_num - 1]) {
                row = mid;
                break;
            }
            else if (target < matrix[mid][0]) down = mid - 1;
            else top = mid + 1;
        }

        int left = 0, right = col_num - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (target == matrix[row][mid]) return true;
            if (target > matrix[row][mid]) left = mid + 1;
            else right = mid - 1;
        }
        return false;
    }
};

// n * m matrix convert to an array => matrix[n][m] => array[x * m + y]
// an array convert to n * m matrix => array[x] => matrix[x / m][x % m]
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return false;

        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = n * m - 1;
        while (l != r) {
            int mid = (l + r - 1) >> 1;
            if (matrix[mid / m][mid % m] < target) l = mid + 1;
            else r = mid;
        }
        return matrix[r / m][r % m] == target;
    }
};
