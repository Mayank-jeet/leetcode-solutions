/*
 * LeetCode:  1367 - Linked List in Binary Tree
 * Link: https://leetcode.com/problems/linked-list-in-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the list
 * Space: O(n) cosidering space used by recursion stack
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool ans=false;
    void hTot(ListNode* head,TreeNode* root){
        if(!head){
            ans=true;
            return;
        }
        if(!root || root->val!=head->val) return;
        hTot(head->next,root->left);
        hTot(head->next,root->right);
    }
    void traverse(ListNode* head, TreeNode* root){
        if(!root) return;
        hTot(head,root);
        if(!ans){
            traverse(head,root->left);
            traverse(head,root->right);
        }
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        traverse(head,root);
        return ans;
    }
};