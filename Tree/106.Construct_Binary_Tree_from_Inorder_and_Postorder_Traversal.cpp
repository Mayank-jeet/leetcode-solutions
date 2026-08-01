/*
 * LeetCode: 106 - Construct Binary Tree from Inorder and Postorder Traversal
 * Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* formTree(vector<int>& inorder, vector<int>& postorder,int postLeft,int postRight,int inLeft,int inRight,unordered_map<int,int>& u_map){
        if(postLeft>postRight || inLeft>inRight) return nullptr;
        TreeNode* root=new TreeNode(postorder[postRight]);
        int index=u_map[root->val];
        int dist=inRight-index;
        root->right=formTree(inorder,postorder,postRight-dist,postRight-1,index+1,inRight,u_map);
        root->left=formTree(inorder,postorder,postLeft,postRight-dist-1,inLeft,index-1,u_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> u_map;
        int n=inorder.size();
        for(int i=0;i<n;i++) u_map[inorder[i]]=i;
        return formTree(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1,u_map);
    }
};