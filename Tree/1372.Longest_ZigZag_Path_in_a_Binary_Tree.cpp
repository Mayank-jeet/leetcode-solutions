/*
 * LeetCode: 1372 - Longest ZigZag Path in a Binary Tree
 * Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void trav(TreeNode* root,bool left,int& ans,int& depth){
        if(!root) return;
        TreeNode* next=left?root->right:root->left;
        depth++;
        ans=max(depth,ans);
        trav(next,!left,ans,depth);
        depth=0;
        next=left?root->left:root->right;
        trav(next,left,ans,depth);
    }
    int longestZigZag(TreeNode* root) {
        int ans=0,depth=-1;
        trav(root,true,ans,depth);
        return ans;
    }
};