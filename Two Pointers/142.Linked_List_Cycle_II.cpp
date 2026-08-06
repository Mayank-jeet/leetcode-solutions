/*
 * LeetCode: 142 - Linked List Cycle II
 * Link: https://leetcode.com/problems/linked-list-cycle-ii/
 * Difficulty: Medium
 * Time: O(1)
 * Space: O(n) where n is the number of nodes in the linked list
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> set;
        while(head){
            if(set.find(head)!=set.end()) return head;
            set.insert(head);
            head=head->next;
        }
        return nullptr;
    }
};