/*
 * LeetCode: 2265 - Count Nodes Equal to Average of Subtree
 * Link: https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) recursive stack space used for traversing the tree 
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> dfs(TreeNode* root,int& ans){
        if(!root){
            return {0,0};
        }
        auto leftTree=dfs(root->left,ans);
        auto rightTree=dfs(root->right,ans);
        int sum=leftTree.first+rightTree.first+root->val;
        int nodes=leftTree.second+rightTree.second+1;
        if(root->val==(sum/nodes)) ans++;
        return {sum,nodes};
    }
    int averageOfSubtree(TreeNode* root) {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
};