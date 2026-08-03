/*
 * LeetCode: 863 - All Nodes Distance K in Binary Tree
 * Link: https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for parent_track map,visited set and queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void formParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track){
        if(!root) return;
        if(root->left) parent_track[root->left]=root;
        if(root->right) parent_track[root->right]=root;
        formParent(root->left,parent_track);
        formParent(root->right,parent_track);
    } 
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        formParent(root,parent_track);
        queue<TreeNode*> q;
        q.push(target);
        unordered_set<TreeNode*> visited;
        visited.insert(target);
        int current_level=0;
        while(!q.empty()){
            if(current_level++==k) break;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && visited.count(current->left)==0){
                    visited.insert(current->left);
                    q.push(current->left);
                }
                if(current->right && visited.count(current->right)==0){
                    visited.insert(current->right);
                    q.push(current->right);
                }
                if(parent_track[current] && visited.count(parent_track[current])==0){
                    visited.insert(parent_track[current]);
                    q.push(parent_track[current]);
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            ans.emplace_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};