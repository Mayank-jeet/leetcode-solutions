/*
 * LeetCode:  1721 - Swapping Nodes in a Linked List
 * Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(1) where n is the number of nodes in the list
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* fKNode=head;
        for(int i=1;i<k;i++){
            fKNode=fKNode->next;
        }
        ListNode* bKNode=head;
        ListNode* front=fKNode;
        while(front->next){
            bKNode=bKNode->next;
            front=front->next;
        }
        int temp=fKNode->val;
        fKNode->val=bKNode->val;
        bKNode->val=temp;
        return head;
    }
};