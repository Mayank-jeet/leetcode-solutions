/*
 * LeetCode: 1721 - Swapping Nodes in a Linked List
 * Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
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