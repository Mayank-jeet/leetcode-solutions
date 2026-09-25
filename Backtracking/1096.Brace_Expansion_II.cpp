/*
 * LeetCode: 1096 - Brace Expansion II
 * Link: https://leetcode.com/problems/brace-expansion-ii/
 * Difficulty: Medium
 * Time: O(K×L) where K is number of unique final strings, and L is length of each final string.
 * Space: O(K×L)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
    set<string> ans;
    void dfs(string s){
        int r=s.find('}');
        if(r==string::npos){
            ans.insert(s);
            return;
        }
        int l=s.rfind('{', r);
        string left=s.substr(0,l);
        string right=s.substr(r+1);
        string inside=s.substr(l+1,r-l-1);
        string part;
        stringstream ss(inside);
        while(getline(ss,part,',')){
            dfs(left+part+right);
        }
    }
public:
    vector<string> braceExpansionII(string expression) {
        dfs(expression);
        return vector<string>(ans.begin(),ans.end());
    }
};