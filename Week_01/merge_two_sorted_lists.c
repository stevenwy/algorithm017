/*
 * =====================================================================================
 *
 *       Filename:  merge_two_sorted_lists.c
 *
 *    Description: LeetCode NO.21 
 *
 *        Version:  1.0
 *        Created:  2020/09/27 23时28分28秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jason (Jason Ding), 
 *   Organization:  
 *
 * =====================================================================================
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if (!l1 && l2) return l2;
    if (l1 && !l2) return l1;
    if (!l1 && !l2) return NULL;
    
    struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummy;

    while (l1 && l2) {
        if (l1->val >= l2->val) {
            tail->next = l2;
            l2 = l2->next;
        } else {
            tail->next = l1;
            l1 = l1->next;
        }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy->next;
}
