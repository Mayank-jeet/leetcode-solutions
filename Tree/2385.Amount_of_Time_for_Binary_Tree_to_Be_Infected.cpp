/*
 * LeetCode: 2385 - Amount of Time for Binary Tree to Be Infected
 * Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) recursive stack space used for traversing the tree and parents map, additional space for visited set
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* startNode;
    void formParent(unordered_map<TreeNode*,TreeNode*>& u_map,TreeNode* root,int& start){
        if(!root) return;
        if(root->left) u_map[root->left]=root;
        if(root->right) u_map[root->right]=root;
        if(root->val==start) startNode=root;
        formParent(u_map,root->left,start);
        formParent(u_map,root->right,start);
    }
    void traverse(unordered_map<TreeNode*,TreeNode*>& parents,unordered_set<TreeNode*>& visited,int& ans,int depth,TreeNode* root){
        if(!root || visited.count(root)!=0) return;
        visited.insert(root);
        ans=max(ans,depth);
        traverse(parents,visited,ans,depth+1,root->left);
        traverse(parents,visited,ans,depth+1,root->right);
        auto it=parents.find(root);
        if(it!=parents.end())traverse(parents,visited,ans,depth+1,it->second);
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parents;
        formParent(parents,root,start);
        unordered_set<TreeNode*> visited;
        int ans=0;
        traverse(parents,visited,ans,0,startNode);
        return ans;
    }
};