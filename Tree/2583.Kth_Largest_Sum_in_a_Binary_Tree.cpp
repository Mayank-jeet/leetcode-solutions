/*
 * LeetCode: 2583 - Kth Largest Sum in a Binary Tree
 * Link: https://leetcode.com/problems/kth-largest-sum-in-a-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for queue and multiset
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        multiset<long long> s;
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        long long chunk=0;
        while(q.size()>0){
            if(q.front()==nullptr){
                q.pop();
                s.insert(chunk);
                chunk=0;
                if(q.size()>0) q.push(nullptr);
            }else{
                chunk+=q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();

            }
        }
        if(s.size()<k) return -1;
        auto it=s.rbegin();
        advance(it,k-1);
        return *it;
    }
};