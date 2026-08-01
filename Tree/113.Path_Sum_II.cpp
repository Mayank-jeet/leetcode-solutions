/*
 * LeetCode: 113 - Path Sum II
 * Link: https://leetcode.com/problems/path-sum-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> ans;
    void sum(TreeNode* root, int targetSum, vector<int> chunk,int sumM){
        if(!root) return;
        sumM+=root->val;
        chunk.emplace_back(root->val);
        if(!root->left && !root->right && sumM==targetSum){
            ans.emplace_back(chunk);
        }
        sum(root->left,targetSum,chunk,sumM);
        sum(root->right,targetSum,chunk,sumM);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> chunk;
        sum(root,targetSum,chunk,0);
        return ans;
    }
};