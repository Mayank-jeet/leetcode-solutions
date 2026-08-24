/*
 * LeetCode: 886 - Possible Bipartition
 * Link: https://leetcode.com/possible-bipartition/
 * Difficulty: Medium
 * Time: O(V+E) where V is number of vertices and E is number of edges
 * Space: O(V+E)
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto el:dislikes) {
            graph[el[0]].emplace_back(el[1]);
            graph[el[1]].emplace_back(el[0]);
        }
        vector<int> visited(n+1,0);
        for(int i=1;i<=n;i++){
            if(visited[i]==0) {
                if(dfs(graph,visited,i,1)==false) return false;
            }
        }
        return true;
    }
};