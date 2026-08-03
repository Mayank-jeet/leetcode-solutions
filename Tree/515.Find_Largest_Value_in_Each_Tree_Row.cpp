/*
 * LeetCode: 515 - Find Largest Value in Each Tree Row
 * Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int max=INT_MIN;
        while(q.size()>0){
            if(q.front()==nullptr){
                ans.emplace_back(max);
                q.pop();
                if(q.size()>0) q.push(nullptr);
                max=INT_MIN;
            }else{
                if(q.front()->val>max) max=q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;

    }
};