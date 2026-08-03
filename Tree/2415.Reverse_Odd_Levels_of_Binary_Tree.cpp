/*
 * LeetCode: 2415 - Reverse Odd Levels of Binary Tree
 * Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root->left) return root;
        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);
        q.push(nullptr);
        int depth=1;
        while(!q.empty()){
            if(q.front()==nullptr){
                depth++;
                q.pop();
                if(!q.empty()){
                    q.push(nullptr);
                }else break;
            }
            TreeNode* leftNode=q.front();
            q.pop();
            TreeNode* rightNode=q.front();
            q.pop();
            if(leftNode->left) {
                q.push(leftNode->left); 
                q.push(rightNode->right);
                q.push(leftNode->right);
                q.push(rightNode->left);
            }
            if(depth%2!=0){
                int temp=leftNode->val;
                leftNode->val=rightNode->val;
                rightNode->val=temp;
            }
        }
        return root;
    }
};