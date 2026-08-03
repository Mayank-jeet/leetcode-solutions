/*
 * LeetCode: 437 - Path Sum III
 * Link: https://leetcode.com/problems/path-sum-iii/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    long long sum=0;
    unordered_map<long long, int >mp;
    void dfs(TreeNode* root, int targetSum){
        if(!root)return;
        sum+=root->val;
        ans+=mp[sum-targetSum];
        mp[sum]++;
        dfs(root->left,targetSum);
        dfs(root->right,targetSum);
        mp[sum]--;
        if(mp[sum]==0)mp.erase(sum);
        sum-=root->val;
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        dfs(root,targetSum);
        return ans;
    }
};