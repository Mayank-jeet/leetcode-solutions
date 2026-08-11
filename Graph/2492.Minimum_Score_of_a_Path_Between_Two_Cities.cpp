/*
 * LeetCode:  2492 - Minimum Score of a Path Between Two Cities
 * Link: https://leetcode.com/problems/minimum-score-of-a-path-between-two-cities/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for vis and adj vectors, as well as queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto el:roads){
            int u=el[0],v=el[1],w=el[2];
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
        queue<int> q;
        q.push(1);
        vector<bool> vis(n+1,false);
        vis[0]=true;vis[1]=true;
        int ans=INT_MAX;
        while(!q.empty()){
            int index=q.front();
            q.pop();
            for(auto [v,w]:adj[index]){
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
                ans=min(ans,w);
            }
        }
        return ans;
    }
};