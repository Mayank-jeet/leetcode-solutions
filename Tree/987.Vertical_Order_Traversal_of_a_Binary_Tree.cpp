/*
 * LeetCode: 987 - Vertical Order Traversal of a Binary Tree
 * Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
 * Difficulty: Hard
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering stack space used for recursive calls and space used by map and ans vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(TreeNode* root,int idx,int depth,map<int,vector<pair<int,int>>>& m){
        if(!root) return;
        m[idx].emplace_back(depth,root->val);
        dfs(root->left,idx-1,depth+1,m);
        dfs(root->right,idx+1,depth+1,m);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<pair<int,int>>> m;
        dfs(root,0,0,m);
        vector<vector<int>> ans;
        for(auto [idx,vec]:m) {
            sort(vec.begin(),vec.end());
            vector<int> col;
            for(auto [row,val]:vec) col.emplace_back(val);
            ans.emplace_back(col);
        }
        return ans;
    }
};