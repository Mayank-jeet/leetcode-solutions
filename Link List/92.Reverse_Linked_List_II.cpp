/*
 * LeetCode: 92 - Reverse Linked List II
 * Link: https://leetcode.com/problems/reverse-linked-list-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* first=head;
        for(int i=0;i<left-1;i++) first=first->next;
        int n=right-left;
        for(int i=0;i<n;i++){
            ListNode* curr=first;
            ListNode* forward=first->next;
            for(int j=i;j<n;j++){
                curr->val=curr->val^forward->val;
                forward->val=curr->val^forward->val;
                curr->val=curr->val^forward->val;
                curr=curr->next;
                forward=forward->next;
            }
        }
        return head;
    }
};