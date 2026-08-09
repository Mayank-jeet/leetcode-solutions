/*
 * LeetCode: 61 - Rotate List
 * Link: https://leetcode.com/problems/rotate-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next) return head;
        int size=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            size++;
        }
        k%=size;
        if(k==0) return head;
        ListNode* left=head;
        ListNode* right=head;
        for(int i=0;i<k;i++) right=right->next;
        while(right->next){
            right=right->next;
            left=left->next;
        }
        ListNode* newHead=left->next;
        left->next=nullptr;
        right->next=head;
        return newHead;
    }
};