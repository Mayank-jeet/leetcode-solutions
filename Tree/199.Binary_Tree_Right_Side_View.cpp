/*
 * LeetCode: 199 - Binary Tree Right Side View
 * Link: https://leetcode.com/problems/binary-tree-right-side-view/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(q.size()>0){
            TreeNode* el=q.front();
            q.pop();
            if(el->left!=nullptr) q.push(el->left);
            if(el->right!=nullptr) q.push(el->right);
            if(q.front()==nullptr){
                ans.emplace_back(el->val);
                q.pop();
                if(q.size()>0) q.push(nullptr);
            }
        }
        return ans;
    }
};