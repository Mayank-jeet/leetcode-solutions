/*
 * LeetCode: 107 - Binary Tree Level Order Traversal II
 * Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> chunk;
        while(q.size()>0){
            if(q.front()==nullptr){
                ans.insert(ans.begin(),chunk);
                chunk.clear();
                q.pop();
                if(q.size()>0) q.push(nullptr); 
            }else{
                if(q.front()->left!=nullptr) q.push(q.front()->left);
                if(q.front()->right!=nullptr) q.push(q.front()->right);
                chunk.push_back(q.front()->val);
                q.pop();
            }
        }
        return ans;
    }
};