/*
 * LeetCode: 2130 - Maximum Twin Sum of a Linked List
 * Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> s;
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(slow->next && fast->next){
            s.push(slow->val);
            slow=slow->next;
            fast=fast->next->next;
        }
        s.push(slow->val);
        int ans=0;
        while(s.size()>0){
            slow=slow->next;
            if((slow->val+s.top())>ans) ans=slow->val+s.top();
            s.pop();
        }
        return ans;
    }
};