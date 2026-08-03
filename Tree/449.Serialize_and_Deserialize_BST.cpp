/*
 * LeetCode: 449 - Serialize and Deserialize BST
 * Link: https://leetcode.com/problems/serialize-and-deserialize-bst/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Codec {
public:
    string s;
    void preOrder(TreeNode* root){
    if(!root) {
        if(s.length()!=0) {
            s += ",";
            s += "-1";
        }
        return;
    }
    s += ",";
    s += to_string(root->val);
    preOrder(root->left);
    preOrder(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        preOrder(root);
        return s;
    }
    int extract(const string& data,int& start){
        int n=data.length();
        int ans;
        for(int i=start;i<n;i++){
            if(data[i]==',') {
                ans=stoi(data.substr(start,i-start));
                start=i;
                break;
            }
            if(i==n-1){
                ans=stoi(data.substr(start,n-start));
                start=n;
                break;
            }
        }
        return ans;
    }
    TreeNode* pot(const string& data,int &start){
        start++;
        if(start>=data.length()) return nullptr;
        int value=extract(data,start);
        if(value==-1) return nullptr;
        TreeNode* root=new TreeNode(value);
        root->left=pot(data,start);
        root->right=pot(data,start);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        s=data;
        int start=0;
        return pot(s,start);
    }
};