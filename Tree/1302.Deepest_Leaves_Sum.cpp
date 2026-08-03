/*
 * LeetCode: 1302 - Deepest Leaves Sum
 * Link: https://leetcode.com/problems/deepest-leaves-sum/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int ans=0,sum=0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        while(!q.empty()){
            if(!q.front()){
                q.pop();
                ans=sum;
                sum=0;
                if(!q.empty()) q.push(nullptr);
                else break;
            }
            sum+=q.front()->val;
            if(q.front()->left) q.push(q.front()->left);
            if(q.front()->right) q.push(q.front()->right);
            q.pop();
        }
        return ans;
    }
};