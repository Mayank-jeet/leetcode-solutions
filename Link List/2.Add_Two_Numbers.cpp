/*
 * LeetCode: 2 - Add Two Numbers
 * Link: https://leetcode.com/problems/add-two-numbers/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* ans=new ListNode(0);
            ListNode* curr=ans;
            int carry=0;
            while(l1 || l2){
                int digit=carry;
                if(l1) {
                    digit+=l1->val;
                    l1=l1->next;
                }
                if(l2) {
                    digit+=l2->val;
                    l2=l2->next;
                }
                carry=digit/10;
                curr->next=new ListNode(digit%10);
                curr=curr->next;
            }
            if(carry!=0) curr->next=new ListNode(carry);
            return ans->next;
        }
};