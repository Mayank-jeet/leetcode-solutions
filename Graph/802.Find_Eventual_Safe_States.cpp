/*
 * LeetCode: 802 - Find Eventual Safe States
 * Link: https://leetcode.com/find-eventual-safe-states/
 * Difficulty: Medium
 * Time: O(V+E) where V is number of vertices and E is number of edges
 * Space: O(V) not cosidering recursion stack space
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_set<int> u_set;
    bool dfs(vector<vector<int>>& graph,vector<bool>& vis,int index,vector<int>& ans){
        if(vis[index]){
            if(u_set.count(index)==0) return false;
            return true;
        }
        vis[index]=true;
        for(int i=0;i<graph[index].size();i++){
            if(dfs(graph,vis,graph[index][i],ans)==false) return false;
        }
        ans.push_back(index);
        u_set.insert(index);
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> ans;
        int n=graph.size();
        vector<bool> vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]) dfs(graph,vis,i,ans);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};