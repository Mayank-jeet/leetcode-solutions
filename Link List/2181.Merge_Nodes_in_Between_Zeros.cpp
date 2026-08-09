/*
 * LeetCode:  2181 - Merge Nodes in Between Zeros
 * Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode* copy=head;
        ListNode* current=copy->next;
        head=current;
        copy->next=nullptr;
        while(current){
            if(current->next) current->val+=current->next->val;
            ListNode* delNode=current->next;
            current->next=current->next->next;
            delNode->next=nullptr;
            if(delNode->val==0) current=current->next;
        }
        return head;
    }
};