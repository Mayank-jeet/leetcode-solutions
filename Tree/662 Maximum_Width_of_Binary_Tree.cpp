/*
 * LeetCode: 662 - Maximum Width of Binary Tree
 * Link: https://leetcode.com/problems/maximum-width-of-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        int ans=1;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int min_index=q.front().second;
            int n=q.size();
            long long  first=0,last=0;
            for(int i=0;i<n;i++){
                TreeNode* current=q.front().first;
                long long index=q.front().second-min_index;
                q.pop();
                if(i==0) first=index;
                else if(i==n-1) last=index;
                if(current->left) q.push({current->left,2*index+1});
                if(current->right) q.push({current->right,2*index+2});
            }
            ans=max(ans,(int)(last-first+1));
        }
        return ans;
    }
};