/*
 * =====================================================================================
 *
 *       Filename:  container_with_most_water.c
 *
 *    Description: LeetCode NO.11 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时43分14秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

int maxArea(int* height, int heightSize){
    int maxArea, i, j;
    maxArea = i = j = 0;
    j = heightSize - 1;
    while (i < j) {
        maxArea = fmax(maxArea, (j - i) * fmin(height[i], height[j]));
        if (height[i] < height[j])
            ++i;
        else
            --j;
    }
    return maxArea;
}
