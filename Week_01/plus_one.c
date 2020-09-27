/*
 * =====================================================================================
 *
 *       Filename:  plus_one.c
 *
 *    Description: LeetCode NO.66 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时40分45秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    // why returnSize = &digitsSize not work, leetcode test code may have bug
    *returnSize = digitsSize;
    for (int i = digitsSize - 1; i >= 0; --i) {
        digits[i] = ++digits[i] % 10;
        if (digits[i] != 0) return digits;
    }
    digits = (int *)calloc(++digitsSize, sizeof(int));
    digits[0] = 1;
    *returnSize = digitsSize;
    return digits;
}
