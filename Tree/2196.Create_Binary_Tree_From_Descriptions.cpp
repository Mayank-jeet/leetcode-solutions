/*
 * LeetCode: 2196 - Create Binary Tree From Descriptions
 * Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used fo map and set
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> map;
        unordered_set<int> children;
        for(int i=0;i<descriptions.size();i++){
            TreeNode *child,*parent;
            if(map.count(descriptions[i][1])==0) {
                child=new TreeNode(descriptions[i][1]);
                map[descriptions[i][1]]=child;
            }else child=map[descriptions[i][1]];
            if(map.count(descriptions[i][0])==0) {
                parent=new TreeNode(descriptions[i][0]);
                map[descriptions[i][0]]=parent;
            }else parent=map[descriptions[i][0]];
            if(descriptions[i][2]==1) parent->left=child;
            else parent->right=child;
            children.insert(descriptions[i][1]);
        }
        for(auto [key,val]:map){
            if(children.count(key)==0) return val;
        }
        return nullptr;
    }
};