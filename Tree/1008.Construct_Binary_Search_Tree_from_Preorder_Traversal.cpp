/*
 * LeetCode: 1008 - Construct Binary Search Tree from Preorder Traversal
 * Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering the recursive stack space used for traversing the tree
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* formTree(vector<int>& preorder,int current,int last){
        if(current>=last || current==preorder.size()) return nullptr;
        TreeNode* root=new TreeNode(preorder[current]);
        int temp=preorder[current];
        int left=current;
        while(current<last && preorder[current]<=temp) current++;
        root->left=formTree(preorder,left+1,current);
        root->right=formTree(preorder,current,last);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return formTree(preorder,0,preorder.size());
    }
};