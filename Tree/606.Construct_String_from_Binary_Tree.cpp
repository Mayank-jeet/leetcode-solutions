/*
 * LeetCode: 606 - Construct String from Binary Tree
 * Link: https://leetcode.com/problems/construct-string-from-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) if we consider the output string as extra space, otherwise O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string s;
    void dfs(TreeNode* root){
        if(!root) {
            s.push_back(')');
            return;
        }
        s+=to_string(root->val);
        if(!root->left && !root->right) {
            s.push_back(')');
            return;
        }
        s.push_back('(');
        dfs(root->left);
        if(root->right){
            s.push_back('(');
            dfs(root->right);
        }
        s.push_back(')');
    }
    string tree2str(TreeNode* root) {
        dfs(root);
        s=s.substr(0,s.size()-1);
        return s;
    }
};