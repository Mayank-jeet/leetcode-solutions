/*
 * LeetCode: 117 - Populating Next Right Pointers in Each Node II
 * Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the binary tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while(q.size()>0){
            Node* temp=q.front();
            q.pop();
            temp->next=q.front();
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
            if(q.front()==nullptr){
                q.pop();
                if(q.size()>0) q.push(nullptr);
            }
        }
        return root;
    }
};