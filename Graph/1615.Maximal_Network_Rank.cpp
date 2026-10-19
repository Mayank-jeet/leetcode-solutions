/*
 * LeetCode: 1615 - Maximal Network Rank
 * Link: https://leetcode.com/problems/maximal-network-rank/
 * Difficulty: Medium
 * Time: O(n^2) where n is number of nodes
 * Space: O(V+E) where V is number of nodes and E is number of edges
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        if(roads.size()==0) return 0;
        else if(roads.size()==1) return 1;
        vector<vector<int>> adj(n);
        for(auto node:roads){
            adj[node[0]].emplace_back(node[1]);
            adj[node[1]].emplace_back(node[0]);
        }
        int maxEdge=0;
        int secondMaxEdge=0;
        for(int i=0;i<n;i++){
            int edgeSize=adj[i].size();
            if(edgeSize>maxEdge){
                secondMaxEdge=maxEdge;
                maxEdge=edgeSize;
            }else if(edgeSize>secondMaxEdge) secondMaxEdge=edgeSize;
        }
        for(int a=0;a<n;a++){
            if((int)adj[a].size()!=maxEdge) continue;
            unordered_set<int> u_set(adj[a].begin(),adj[a].end());
            for(int i=0;i<n;i++){
                if(i==a) continue;
                if((int)adj[i].size()==secondMaxEdge && u_set.count(i)==0) return maxEdge+secondMaxEdge;
            }
        }
        return maxEdge+secondMaxEdge-1;
    }
};