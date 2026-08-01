/*
 * LeetCode: 230 - Kth Smallest Element in a BST
 * Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    multiset<int> m_set;
    void preTrav(TreeNode* root){
        if(!root) return;
        m_set.insert(root->val);
        preTrav(root->left);
        preTrav(root->right);
    }
    int kthSmallest(TreeNode* root, int k) {
        preTrav(root);
        auto it=m_set.begin();
        advance(it,k-1);
        return *it;
    }
};