/*
 * LeetCode:  2058 - Find the Minimum and Maximum Number of Nodes Between Critical Points
 * Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(n) considering space used for answer vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans(2,-1);
        ListNode* prevNode=head;
        ListNode* current=head->next;
        int i=0,first=-1,prev=-1;
        while(current && current->next){
            i++;
            if(current->val>prevNode->val && current->val>current->next->val){
                if(first==-1){
                    first=i;
                }
                else{
                    if(ans[0]==-1 || (i-prev)<ans[0]) ans[0]=(i-prev);
                    ans[1]=i-first;
                }
                prev=i;
            }
            else if(current->val<prevNode->val && current->val<current->next->val){
                if(first==-1){
                    first=i;
                }
                else{
                    if(ans[0]==-1 || (i-prev)<ans[0]) ans[0]=(i-prev);
                    ans[1]=i-first;
                }
                prev=i;
            }
            prevNode=prevNode->next;
            current=current->next;
        }
        return ans;
    }
};