/*
 * LeetCode: 124 - Binary Tree Maximum Path Sum
 * Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/
 * Difficulty: Hard
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) sconsidering stack space used for recursive calls
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pathSum(TreeNode* root,int& sum){
        if(!root) return 0;
        int lf=max(0,pathSum(root->left,sum));
        int rt=max(0,pathSum(root->right,sum));
        sum=max(sum,lf+rt+root->val);
        return root->val+max(lf,rt);
    }
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
        pathSum(root,ans);
        return ans;
    }
};