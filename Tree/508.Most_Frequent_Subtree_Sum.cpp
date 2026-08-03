/*
 * LeetCode: 508 - Most Frequent Subtree Sum
 * Link: https://leetcode.com/problems/most-frequent-subtree-sum/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,int> u_map;
    void subtreeSum(TreeNode* root,int& sum){
        if(!root) return;
        sum+=root->val;
        subtreeSum(root->left,sum);
        subtreeSum(root->right,sum);
    }
    void traverse(TreeNode* root){
        if(!root) return;
        int sum=0;
        subtreeSum(root,sum);
        u_map[sum]+=1;
        traverse(root->left);
        traverse(root->right);
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        traverse(root);
        vector<int> ans;
        int max=0;
        for(auto el:u_map){
            if(el.second>max){
                ans.clear();
                max=el.second;
                ans.emplace_back(el.first);
            }
            else if(el.second==max) ans.emplace_back(el.first);
        }
        return ans;
    }
};