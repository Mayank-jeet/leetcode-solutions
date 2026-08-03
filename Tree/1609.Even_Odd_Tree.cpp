/*
 * LeetCode: 1609 - Even Odd Tree
 * Link: https://leetcode.com/problems/even-odd-tree/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int level=0;
        int prev=q.front()->val;
        bool first=true;
        while(q.size()>0){
            if(q.front()==nullptr){
                q.pop();
                level+=1;
                if(q.size()>0){
                    q.push(nullptr);
                    first=true;
                }
            }else{
                if(level%2==0){
                    if(first){
                        if(q.front()->val%2==0) return false;
                        first=false;
                    }
                    else{
                        if(q.front()->val%2==0 || q.front()->val<=prev) return false;
                    }

                }
                else{
                    if(first){
                        if(q.front()->val%2!=0) return false;
                        first=false;
                    }
                    else{
                        if(q.front()->val%2!=0 || q.front()->val>=prev) return false;
                    }
                }
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                prev=q.front()->val; 
                q.pop();
            }
        }
        return true;
    }
};