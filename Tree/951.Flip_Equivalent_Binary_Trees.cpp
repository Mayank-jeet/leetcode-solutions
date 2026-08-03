/*
 * LeetCode: 951 - Flip Equivalent Binary Trees
 * Link: https://leetcode.com/problems/flip-equivalent-binary-trees/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void traverse(TreeNode* root1, TreeNode* root2, bool& ans){
        if(!root1 && !root2) return;
        else if(!root1 && root2 || root1 && !root2){
            ans=false;
            return;
        }
        if(((!root1->left && !root2->left) || ((root1->left && root2->left) && (root1->left->val==root2->left->val))) && ((!root1->right && !root2->right) || ((root1->right && root2->right) && (root1->right->val==root2->right->val)))){
            traverse(root1->left,root2->left,ans);
            traverse(root1->right,root2->right,ans);
        }
       else if(((!root1->left && !root2->right) || ((root1->left && root2->right) && (root1->left->val==root2->right->val))) && ((!root1->right && !root2->left) || ((root1->right && root2->left) && (root1->right->val==root2->left->val)))){
            traverse(root1->left,root2->right,ans);
            traverse(root1->right,root2->left,ans);
       }
       else ans=false;
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 && !root2) return true;
        if((!root1 && root2) || (root1 && !root2) || root1->val!=root2->val) return false;
        bool ans=true;
        traverse(root1,root2,ans);
        return ans;
    }
};