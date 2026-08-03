/*
 * LeetCode: 1325 - Delete Leaves With a Given Value
 * Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void delNode(TreeNode* root, int target){
        if(!root) return;
        delNode(root->left,target);
        delNode(root->right,target);
        if(root->left!=nullptr && root->left->val==target){
            if(root->left->left==nullptr && root->left->right==nullptr) root->left=nullptr;
        }
        if(root->right!=nullptr && root->right->val==target){
            if(root->right->left==nullptr && root->right->right==nullptr) root->right=nullptr;
        }
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        delNode(root, target);
        if(!root->left && !root->right && root->val==target) return nullptr;
        return root;
    }
};