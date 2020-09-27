/*
 * =====================================================================================
 *
 *       Filename:  remove_duplicates_from_sorted_array.c
 *
 *    Description: LeetCode NO.26 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时02分01秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <stdio.h>


void printArray(int* nums, int length);
int removeDuplicates(int* nums, int numsSize);

int main() {
    int arr[] = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int *nums = &arr[0];
    int numsSize = 10;
    int length = removeDuplicates(nums, numsSize);
    printf("Expect result: [0, 1, 2, 3, 4]\n");
    printArray(nums, length);
    return 0;
}

// double pointer(slow fast pointer)
int removeDuplicates(int* nums, int numsSize) {
    if (numsSize < 2) return numsSize;

    int j = 0;
    for (int i = 1; i < numsSize; ++i) {
        if (nums[j] != nums[i]) {
            ++j;
            nums[j] = nums[i];
        }
    }
    return ++j;
}

// helper method
void printArray(int* nums, int length) {
    if (length == 0) printf("[]\n");

    for (int i = 0; i < length; ++i)
        printf("nums[%d]: %d\n", i, nums[i]);
}
