/*
 * LeetCode:  851 - Loud and Rich
 * Link: https://leetcode.com/problems/loud-and-rich/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int start,vector<bool>& vis,vector<vector<int>>& adj,vector<int>& quiet,pair<int,int> &chunk){
        for(auto el:adj[start]){
            if(!vis[el]){
                vis[el]=true;
                if(chunk.second>quiet[el]) chunk={el,quiet[el]};
                dfs(el,vis,adj,quiet,chunk);
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<vector<int>> adj(n);
        for(auto el:richer){
            int v=el[0],u=el[1];
            adj[u].emplace_back(v);
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            vector<bool> vis(n,false);
            pair<int,int> chunk={i,quiet[i]};
            dfs(i,vis,adj,quiet,chunk);
            ans.emplace_back(chunk.first);
        }
        return ans;
    }
};