/*
 * LeetCode: 785 - Is Graph Bipartite?
 * Link: https://leetcode.com/is-graph-bipartite/
 * Difficulty: Medium
 * Time: O(V+E)
 * Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool dfs(vector<vector<int>>& graph,vector<int>& visited,int index,int color){
        if(visited[index]!=0){
            if(visited[index]!=color) return false;
            return true;
        }
        visited[index]=color;
        for(int i=0;i<graph[index].size();i++){
            if(dfs(graph,visited,graph[index][i],-1*color)==false){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]==0) {
                if(dfs(graph,visited,i,1)==false) return false;
            }
        }
        return true;
    }
};