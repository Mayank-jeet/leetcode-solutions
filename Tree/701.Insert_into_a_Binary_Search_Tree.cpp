/*
 * LeetCode: 701 - Insert into a Binary Search Tree
 * Link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root) return new TreeNode(val);
        TreeNode* curr=root;
        while(curr){
            if(curr->val>val){
                if(!curr->left){
                    curr->left=new TreeNode(val);
                    return root;
                }else{
                    curr=curr->left;
                }
            }else{
                if(!curr->right){
                    curr->right=new TreeNode(val);
                    return root;
                }else{
                    curr=curr->right;
                }
            }
        }
        return root;
    }
};