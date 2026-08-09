/*
 * LeetCode: 143 - Reorder List
 * Link: https://leetcode.com/problems/reorder-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the linked list
 * Space: O(n) for the stack used to store the nodes in the linked list
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;
        ListNode* slow=head;
        ListNode* fast=head;
        stack<ListNode*> s;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        while(slow){
            slow=slow->next;
            if(slow) s.push(slow);
        }
        slow=head;
        while(!s.empty()){
            ListNode* copy=slow->next;
            slow->next=s.top();
            s.top()->next=copy;
            s.pop();
            slow=slow->next->next;
        }
        slow->next=nullptr;
    }
};