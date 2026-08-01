/*
 * LeetCode: 105 - Construct Binary Tree from Preorder and Inorder Traversal
 * Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* formTree(vector<int>& preorder, vector<int>& inorder,int preLeft,int preRight,int inLeft,int inRight,unordered_map<int,int>& u_map){
        if(preLeft>preRight || inLeft>inRight) return nullptr;
        TreeNode* root=new TreeNode(preorder[preLeft]);
        int index=u_map[preorder[preLeft]];
        int left=index-inLeft;
        root->left=formTree(preorder,inorder,preLeft+1,preLeft+left,inLeft,index-1,u_map);
        root->right=formTree(preorder,inorder,preLeft+left+1,preRight,index+1,inRight,u_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> u_map;
        int n=inorder.size();
        for(int i=0;i<n;i++) u_map[inorder[i]]=i;
        return formTree(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1,u_map);
    }
};