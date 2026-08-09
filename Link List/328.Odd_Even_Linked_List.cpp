/*
 * LeetCode: 328 - Odd Even Linked List
 * Link: https://leetcode.com/problems/odd-even-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return head;
        ListNode* curr=head;
        ListNode* forward=head->next;
        ListNode* second=forward;
        while(forward->next){
            curr->next=forward->next;
            if(curr->next) curr=curr->next;
            if(curr->next) {
                forward->next=curr->next;
                forward=forward->next;
            }else forward->next=nullptr;
        }
        curr->next=second;
        return head;
    }
};
