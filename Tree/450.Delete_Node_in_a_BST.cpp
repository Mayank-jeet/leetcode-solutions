/*
 * LeetCode: 450 - Delete Node in a BST
 * Link: https://leetcode.com/problems/delete-node-in-a-bst/
 * Difficulty: Medium
 * Time: O(log(n))
 * Space: O(n) considering the recursion stack
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void findNode(TreeNode* root,TreeNode*& parent,int& key){
        if(!root || parent) return;
        if(root->left && root->left->val==key) parent=root;
        else if(root->right && root->right->val==key) parent=root;
        root->val>key?findNode(root->left,parent,key):findNode(root->right,parent,key);
    }
    TreeNode* modify(TreeNode* root){
        TreeNode* temp=nullptr;
        if(root->right){
            if(root->left) setLeft(root->right,root->left);
            temp=root->right;
            root->right=nullptr;
        }else{
            temp=root->left;
        }
        root->left=nullptr;
        return temp;
    }
    void setLeft(TreeNode* root,TreeNode* left){
        while(root->left) root=root->left;
        root->left=left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        else if(root->val==key) return modify(root);
        TreeNode* parent=nullptr;
        findNode(root,parent,key);
        if(!parent) return root;
        TreeNode* delNode=nullptr;
        bool isLeft=false;
        if(parent->left && parent->left->val==key){ delNode=parent->left; isLeft=true; }
        else delNode=parent->right;
        TreeNode* temp=modify(delNode);
        if(isLeft) parent->left=temp;
        else parent->right=temp;
        return root;
    }
};