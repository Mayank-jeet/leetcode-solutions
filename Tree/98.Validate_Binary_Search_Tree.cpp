/*
 * LeetCode: 98 - Validate Binary Search Tree
 * Link: https://leetcode.com/problems/validate-binary-search-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(TreeNode* root,long maxLimit, long minLimit,bool& ans){
        if(!root || !ans) return;
        if(root->val<minLimit || root->val>maxLimit) ans=false;
        dfs(root->left,(long long)root->val-1,minLimit,ans);
        dfs(root->right,maxLimit,(long long)root->val+1,ans);
    }
    bool isValidBST(TreeNode* root) {
        bool ans=true;
        dfs(root->left,(long long)root->val-1,INT_MIN,ans);
        dfs(root->right,INT_MAX,(long long)root->val+1,ans);
        return ans;
    }
};