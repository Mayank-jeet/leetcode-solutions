/*
 * LeetCode:  1466 - Reorder Routes to Make All Paths Lead to the City Zero
 * Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for vis and adj vectors, as well as stack space used for recursion
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int ans=0;
    void dfs(int index,vector<bool>& vis,vector<vector<pair<int,int>>>& adj){
        for(auto [node,conn]:adj[index]){
            if(!vis[node]){
                vis[node]=true;
                if(conn==-1) ans++;
                dfs(node,vis,adj);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto el:connections){
            int u=el[0],v=el[1];
            adj[u].emplace_back(v,-1);
            adj[v].emplace_back(u,1);
        }
        vector<bool> vis(n,false);
        vis[0]=true;
        dfs(0,vis,adj);
        return ans;
    }
};