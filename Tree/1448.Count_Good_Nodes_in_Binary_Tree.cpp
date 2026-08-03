/*
 * LeetCode: 1448 - Count Good Nodes in Binary Tree
 * Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(TreeNode* root,int & ans,int maximum){
        if(!root) return;
        if(maximum<=root->val) ans++;
        maximum=max(maximum,root->val);
        dfs(root->left,ans,maximum);
        dfs(root->right,ans,maximum);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        dfs(root,ans,INT_MIN);
        return ans;
    }
};