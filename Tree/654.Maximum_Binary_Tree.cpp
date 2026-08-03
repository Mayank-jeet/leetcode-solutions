/*
 * LeetCode: 654 - Maximum Binary Tree
 * Link: https://leetcode.com/problems/maximum-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(1) not including the space used by the output tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size()==0) return nullptr;
        int max=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>nums[max]) max=i; 
        }
        TreeNode* root=new TreeNode(nums[max]);
        if(max==0) root->left=nullptr;
        else{
            vector<int> vec(nums.begin(),nums.begin()+max);
            root->left=constructMaximumBinaryTree(vec);
        }
        if(max==nums.size()-1) root->right=nullptr;
        else{
            vector<int> vec(nums.begin()+max+1,nums.end());
            root->right=constructMaximumBinaryTree(vec);
        }
        return root;
    }
};