/*
 * LeetCode: 19 - Remove Nth Node From End of List
 * Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next) return nullptr;
        ListNode* fast=head;
        for(int i=0;i<n;i++) fast=fast->next;
        ListNode* prevNode=head;
        while(fast && fast->next){
            fast=fast->next;
            prevNode=prevNode->next;
        }
        if(!fast){
            ListNode* delNode=head;
            head=head->next;
            delete delNode;
        }else{
            ListNode* delNode=prevNode->next;
            prevNode->next=prevNode->next->next;
            delete delNode;
        }
        return head;
    }
};