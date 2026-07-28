/*
 * LeetCode: 103 - Binary Tree Zigzag Level Order Traversal
 * Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool left=true;
        while(!dq.empty()){
            int n=dq.size();
            vector<int> chunk;
            for(int i=0;i<n;i++){
                TreeNode* current;
                if(left){
                    current=dq.front();
                    if(current->left) dq.push_back(current->left);
                    if(current->right) dq.push_back(current->right);
                    dq.pop_front();
                }else{
                    current=dq.back();
                    if(current->right) dq.push_front(current->right);
                    if(current->left) dq.push_front(current->left);
                    dq.pop_back();
                }
                chunk.push_back(current->val);
            }
            ans.emplace_back(chunk);
            left=!left;
        }
        return ans;
    }
};
