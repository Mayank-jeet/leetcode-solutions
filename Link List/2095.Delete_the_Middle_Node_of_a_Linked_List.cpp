/*
 * LeetCode:  2095 - Delete the Middle Node of a Linked List
 * Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(1) where n is the number of nodes in the list
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head->next) return nullptr;
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast && fast->next){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=slow->next;
        slow->next=nullptr;
        delete slow;
        return head;
    }
};