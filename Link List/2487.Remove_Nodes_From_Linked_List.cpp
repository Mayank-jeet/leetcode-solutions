/*
 * LeetCode:  2487 - Remove Nodes From Linked List
 * Link: https://leetcode.com/problems/remove-nodes-from-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(n) space used for stack
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* temp=head->next;
        stack<ListNode*> st;
        st.push(head);
        while(temp){
            while(!st.empty() && temp->val>st.top()->val){
                ListNode* delNode=st.top();
                st.pop();
                delNode->next=nullptr;
                if(st.empty()) head=temp;
                else st.top()->next=temp;
            }
            st.push(temp);
            temp=temp->next;
        }
        return head;
    }
};