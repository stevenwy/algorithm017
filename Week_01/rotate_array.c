/*
 * =====================================================================================
 *
 *       Filename:  rotate_array.c
 *
 *    Description: LeetCode: NO.189 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时22分36秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

// 1. 暴力：calloc一个相同长度的array
void rotate(int* nums, int numsSize, int k){
    if (numsSize < 2) return;
    if (k == 0) return;
    
    for (int i = 0; i < k; ++i) {
        int tmp = nums[numsSize - 1];
        int j = numsSize - 1;
        while (j > 0) {
            nums[j] = nums[j - 1];
            j = --j;
        }
        nums[0] = tmp;
    }
}

// 2.
// In-place solution: 参考insertionSort思想，每次旋转插入到array头部，其他所有元素向后移动
// Time complexity: O(kn);
void rotate(int* nums, int numsSize, int k){
    if (numsSize < 2) return;
    if (k == 0) return;
    
    int* a = calloc(1, sizeof(int[numsSize]));
    for (int i = k; i > 0; --i)
        a[k - i] = nums[numsSize - i];
    
    for (int i = 0; i < numsSize - k; ++i)
        a[i + k] = nums[i];
    
    nums = a;
} 

// TODO: Cyclic Replacements
