/*
 * LeetCode: 129 - Sum Root to Leaf Numbers
 * Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> num;
    void sum(TreeNode* root,int chunk){
        if(!root) return;
        chunk=chunk*10+root->val;
        if(!root->left && !root->right){
            num.emplace_back(chunk);
        }
        sum(root->left,chunk);
        sum(root->right,chunk);
    }
    int sumNumbers(TreeNode* root) {
        sum(root,0);
        return accumulate(num.begin(),num.end(),0);
    }
};