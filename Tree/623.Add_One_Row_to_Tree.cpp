/*
 * LeetCode: 623 - Add One Row to Tree
 * Link: https://leetcode.com/problems/add-one-row-to-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) stack space for recursion
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void create(TreeNode* root, int val, int depth, int current){
        if(!root) return;
        if(depth==current+1){
            TreeNode* tempL= root->left;
            TreeNode* tempR= root->right;
            TreeNode* newNodeL=new TreeNode(val);
            TreeNode* newNodeR=new TreeNode(val);
            root->left=newNodeL;
            root->right=newNodeR;
            newNodeL->left=tempL;
            newNodeR->right=tempR;
            return;
        }
        create(root->left,val,depth,current+1);
        create(root->right,val,depth,current+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* newNode=new TreeNode(val);
            newNode->left=root;
            return newNode;
        }
        create(root,val,depth,1);
        return root;
    }
};