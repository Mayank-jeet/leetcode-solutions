/*
 * LeetCode: 297 - Serialize and Deserialize Binary Tree
 * Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
 * Difficulty: Hard
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) 
 */
#include <bits/stdc++.h>
using namespace std;
class Codec {
public:
    // Encodes a tree to a single string.
    void preorderTrav(TreeNode* root,string& str){
        if(!root){
            str+="n,";
            return;
        }
        str+=to_string(root->val)+",";
        preorderTrav(root->left,str);
        preorderTrav(root->right,str);
    }
    string serialize(TreeNode* root) {
        string str;
        preorderTrav(root,str);
        return str;
    }
    TreeNode* formTreeFromPreorder(string& data,int& index){
        if(index==data.size()) return nullptr;
        string s;
        while(index<data.size() && data[index]!=','){
            s.push_back(data[index]);
            index++;
        }
        index++;
        if(s=="n") return nullptr;
        TreeNode* root=new TreeNode(stoi(s));
        root->left=formTreeFromPreorder(data,index);
        root->right=formTreeFromPreorder(data,index);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int index=0;
        return formTreeFromPreorder(data,index);
    }
};