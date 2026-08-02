/*
 * LeetCode: 429 - N-ary Tree Level Order Traversal
 * Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> chunk;
        while(q.size()>0){
            if(!q.front()){
                q.pop();
                ans.emplace_back(chunk);
                chunk.clear();
                if(q.size()>0) q.push(nullptr);
            }else {
                chunk.emplace_back(q.front()->val);
                for(int i=0;i<(q.front()->children).size();i++){
                    if(q.front()->children[i]) q.push((q.front()->children)[i]);
                }
                q.pop();
            }
        }
        return ans;
    }
};