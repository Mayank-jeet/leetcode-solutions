/*
 * LeetCode: 331 - Verify Preorder Serialization of a Binary Tree
 * Link: https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) stack space for recursion
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(string& preorder,int& index,bool& ans){
        if(index>=preorder.length()) {
            ans=false;
            return;
        }
        string str;
        int n=preorder.length();
        while(preorder[index]!=',' && index<n){
            str.push_back(preorder[index]);
            index++;
        }
        index++;
        if(str=="#") return;
        dfs(preorder,index,ans);
        dfs(preorder,index,ans);
    }
    bool isValidSerialization(string preorder) {
        int index=0;
        bool ans=true;
        dfs(preorder,index,ans);
        if(!ans || index<preorder.length()) return false;
        return true;
    }
};