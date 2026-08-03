/*
 * LeetCode: 1315 - Sum of Nodes with Even-Valued Grandparent
 * Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    void twoLevel(TreeNode* root,int level){
        if(!root) return;
        if(level==2) {
            ans+=root->val;
            return;
        }
        twoLevel(root->left,level+1);
        twoLevel(root->right,level+1);
    }
    void gp(TreeNode* root){
        if(!root) return;
        if(root->val%2==0) twoLevel(root,0);
        gp(root->left);
        gp(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        gp(root);
        return ans;
    }
};