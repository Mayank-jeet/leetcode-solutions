/*
 * LeetCode: 82 - Remove Duplicates from Sorted List II
 * Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* forward=head->next;
        while(forward && head && head->val==forward->val){
            while(forward && head->val==forward->val){
                head->next=forward->next;
                forward->next=nullptr;
                delete forward;
                forward=head->next;
            }
            ListNode* delNode=head;
            head=forward;
            delNode->next=nullptr;
            delete delNode;
            if(head) forward=head->next;
        }
        if(!head || !forward || !forward->next) return head;
        ListNode* doubleForward=forward->next;
        ListNode* curr=head;
        bool duplicate=false;
        while(doubleForward){
            if(forward->val==doubleForward->val){
                duplicate=true;
                forward->next=doubleForward->next;
                doubleForward->next=nullptr;
                delete doubleForward;
                doubleForward=forward->next;
            }else if(duplicate){
                curr->next=forward->next;
                ListNode* delNode=forward;
                forward=forward->next;
                delNode->next=nullptr;
                delete delNode;
                if(forward) doubleForward=forward->next;
                duplicate=false;
            }else{
                curr=curr->next;
                forward=forward->next;
                doubleForward=doubleForward->next;
            }
        }
        if(duplicate){
            curr->next=doubleForward;
            delete forward;
        }
        return head;
    }
};