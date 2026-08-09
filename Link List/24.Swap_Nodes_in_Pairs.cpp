/*
 * LeetCode: 24 - Swap Nodes in Pairs
 * Link: https://leetcode.com/problems/swap-nodes-in-pairs/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* swapPairs(ListNode* head){
        if(!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* forward=head->next;
        while(true){
            curr->val=forward->val^curr->val;
            forward->val=forward->val^curr->val;
            curr->val=forward->val^curr->val;
            if(!curr->next->next || !forward->next->next) return head;
            curr=curr->next->next;
            forward=forward->next->next;
        }
        return head;
    }
};