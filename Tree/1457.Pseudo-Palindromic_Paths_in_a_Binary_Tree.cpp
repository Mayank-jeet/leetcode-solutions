/*
 * LeetCode: 1457 - Pseudo-Palindromic Paths in a Binary Tree
 * Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree and from the unordered_map used to store the frequency of node values
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(TreeNode* root,unordered_map<int,int>& u_map,int& count,int odd,int& ans){
        if(!root) return;
        u_map[root->val]++;
        if(u_map[root->val]%2!=0) odd++;
        else odd--;
        count++;
        if(!root->left && !root->right){
            if(odd==0) ans++;
            else if(count%2!=0 && odd==1) ans++;
        }
        dfs(root->left,u_map,count,odd,ans);
        dfs(root->right,u_map,count,odd,ans);
        if(u_map[root->val]%2==0) odd++;
        else odd--;
        u_map[root->val]--;
        count--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> u_map;
        int count=0,ans=0,odd=0;
        dfs(root,u_map,count,odd,ans);
        return ans;
    }
};