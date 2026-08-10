/*
 * LeetCode:  2326 - Spiral Matrix IV
 * Link: https://leetcode.com/problems/spiral-matrix-iv/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(n) considering space used for answer vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int right=n-1,down=m-1,left=0,up=1,i=0,j=0;
        while(head){
            while(j<=right && head){
                ans[i][j]=head->val;
                j++;
                head=head->next;
            }
            j--;
            right--;
            i++;
            while(i<=down && head){
                ans[i][j]=head->val;
                i++;
                head=head->next;
            }
            i--;
            down--;
            j--;
            while(j>=left && head){
                ans[i][j]=head->val;
                j--;
                head=head->next;
            }
            j++;
            left++;
            i--;
            while(i>=up && head){
                ans[i][j]=head->val;
                i--;
                head=head->next;
            }
            i++;
            up++;
            j++;
        }
        return ans;
    }
};