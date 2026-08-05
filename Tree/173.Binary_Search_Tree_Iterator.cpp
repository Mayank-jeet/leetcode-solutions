/*
 * LeetCode: 173 - Binary Search Tree Iterator
 * Link: https://leetcode.com/problems/binary-search-tree-iterator/
 * Difficulty: Medium
 * Time: O(1)
 * Space: O(h) where h is the height of the binary search tree
 */ 
#include <bits/stdc++.h>
using namespace std;
class BSTIterator {
private: stack<TreeNode*> s;
public:
    BSTIterator(TreeNode* root) {
        form(root);
    }
    
    int next() {
        TreeNode* node=s.top();
        s.pop();
        form(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !s.empty();
    }
private:
    void form(TreeNode* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }
};