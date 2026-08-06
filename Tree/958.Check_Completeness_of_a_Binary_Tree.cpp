/*
 * LeetCode: 958 - Check Completeness of a Binary Tree
 * Link: https://leetcode.com/problems/check-completeness-of-a-binary-tree/
 * Difficulty: Medium
 * Time: O(n) is number of nodes in the tree
 * Space: O(n) space for queue, otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int nodes=1;
        bool gotNull=false;
        while(!q.empty()){
            bool nullFound=false;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();q.pop();
                if(current->left) {
                    if(nullFound) return false;
                    q.push(current->left);
                }
                else {
                    nullFound=true;
                    gotNull=true;
                }
                if(current->right) {
                    if(nullFound) return false;
                    q.push(current->right);
                }
                else {
                    nullFound=true;
                    gotNull=true;
                }
            }
            if(gotNull && n<nodes && !q.empty()) return false;
            nodes*=2;
        }
        return true;
    }
};