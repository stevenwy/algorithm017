/*
 * =====================================================================================
 *
 *       Filename:  move_zeros.c
 *
 *    Description: LeetCode NO.283 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时40分06秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

void moveZeroes(int* nums, int numsSize){
    if (numsSize == 0) return;
    
    int j = 0;
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] != 0) {
            int tmp = nums[j];
            nums[j] = nums[i];
            nums[i] = tmp;
            j++;
        }
    }
}
