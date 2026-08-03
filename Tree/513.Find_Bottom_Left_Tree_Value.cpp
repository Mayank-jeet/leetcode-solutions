/*
 * LeetCode: 513 - Find Bottom Left Tree Value
 * Link: https://leetcode.com/problems/find-bottom-left-tree-value/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int ans=root->val;
        while(q.size()>0){
            if(q.front()==nullptr){
                q.pop();
                if(q.size()>0){
                    ans=q.front()->val;
                    q.push(nullptr);
                }
            }else{
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }
};