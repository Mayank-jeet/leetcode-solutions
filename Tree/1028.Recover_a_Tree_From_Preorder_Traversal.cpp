/*
 * LeetCode: 1028 - Recover a Tree From Preorder Traversal
 * Link: https://leetcode.com/problems/recover-a-tree-from-preorder-traversal/
 * Difficulty: Hard
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) considering stack space used for recursive calls
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* formTree(string& traversal,int& index,int level){
        if(index==traversal.length()) return nullptr;
        int depth=0;
        int i=index;
        while(i<traversal.length() && traversal[i]=='-') {
            depth++;
            i++;
        }
        if(level!=depth) return nullptr;
        string str;
        index=i;
        while(index<traversal.length() && traversal[index]!='-'){
            str.push_back(traversal[index]);
            index++;
        }
        TreeNode* root= new TreeNode(stoi(str));
        root->left=formTree(traversal,index,level+1);
        root->right=formTree(traversal,index,level+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string traversal) {
        int index=0;
        return formTree(traversal,index,0);
    }
};