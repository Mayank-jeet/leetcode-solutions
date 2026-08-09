/*
 * LeetCode: 1019 - Next Greater Node In Linked List
 * Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the array
 * Space: O(n) for the stack and the result array
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;
        stack<pair<int,int>> s;
        int index=-1;
        while(head){
            index++;
            ans.emplace_back(0);
            while(!s.empty() && s.top().second<head->val){
                ans[s.top().first]=head->val;
                s.pop();
            }
            s.push(make_pair(index,head->val));
            head=head->next;
        }
        return ans;
    }
};