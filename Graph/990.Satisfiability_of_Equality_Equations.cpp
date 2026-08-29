/*
 * LeetCode: 990 - Satisfiability of Equality Equations
 * Link: https://leetcode.com/satisfiability-of-equality-equations/
 * Difficulty: Medium
 * Time: O(n) where n is size of input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> parent(26);
        for(int i=0;i<26;i++) parent[i]=i;
        for(string s:equations){
            if(s[1]=='=') parent[findParent(s[0]-'a',parent)]=findParent(s[3]-'a',parent);
        }
        for(string s:equations){
            if(s[1]=='!' && findParent(s[0]-'a',parent)==findParent(s[3]-'a',parent)) return false;
        }
        return true;
    }
    int findParent(int x,vector<int>& parent){
        if(x!=parent[x]) parent[x]=findParent(parent[x],parent);
        return parent[x];
    }
};