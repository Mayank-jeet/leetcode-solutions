/*
 * LeetCode: 99 - Recover Binary Search Tree
 * Link: https://leetcode.com/problems/recover-binary-search-tree/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) considering stack space for recursion, otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* prev=nullptr, *first=nullptr,*second=nullptr;
    void utility (TreeNode* root){
        if(root==nullptr) return;
        utility(root->left);
        if(prev!=nullptr && root->val<prev->val){
            if(first==nullptr) first=prev;
            second=root;
        }
        prev=root;
        utility(root->right);
    }
    void recoverTree(TreeNode* root) {
        utility(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};