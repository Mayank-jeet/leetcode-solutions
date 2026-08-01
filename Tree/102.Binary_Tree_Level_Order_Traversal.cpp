/*
 * LeetCode: 102 - Binary Tree Level Order Traversal
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr); 
        vector<int> chunk;
        while(q.size() > 0){
            if(q.front() == nullptr){
                q.pop();
                ans.emplace_back(chunk);
                chunk.clear();
                if(q.size() > 0) q.push(nullptr);
            } 
            else {
                chunk.emplace_back(q.front()->val);
                if(q.front()->left)  q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }
};