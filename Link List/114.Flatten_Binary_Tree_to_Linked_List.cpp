/*
 * LeetCode: 114 - Flatten Binary Tree to Linked List
 * Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the binary tree
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root) return;
        // if(!root->left && !root->right) return;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        root->left=nullptr;
        if (l) root->right=l;
        flatten(l);
        while(l && l->right) l=l->right;
        if(r && l) l->right=r;
        flatten(r);
        return;
    }
};