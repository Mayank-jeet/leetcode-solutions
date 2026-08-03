/*
 * LeetCode: 1161 - Maximum Level Sum of a Binary Tree
 * Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int max=INT_MIN,sum=0,level=0,ans=0;
        while(q.size()>0){
            if(!q.front()){
                q.pop();
                level+=1;
                if(sum>max){
                    max=sum;
                    ans=level;
                }
                if(q.size()>0) q.push(nullptr);
                sum=0;
            }else{
                sum+=q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return ans;
    }
};