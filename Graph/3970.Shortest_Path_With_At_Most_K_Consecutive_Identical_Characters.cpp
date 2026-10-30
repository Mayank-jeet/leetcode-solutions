/*
 * LeetCode: 3970 - Shortest Path With At Most K Consecutive Identical Characters
 * Link: https://leetcode.com/problems/shortest-path-with-at-most-k-consecutive-identical-characters/
 * Difficulty: Medium
 * Time: O(E·k·log(V·k)) where V is the number of nodes (n), E is the number of edges (edges.size()), and k is the maximum allowed consecutive identical characters
 * Space: O(V·k+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int shortestPath(int n,vector<vector<int>>& edges,string labels,int k){
        vector<vector<pair<int,int>>> adj(n);
        for(auto& it:edges){
            adj[it[0]].emplace_back(it[1],it[2]);
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> m(n,vector<int>(k+1,INT_MAX));
        m[0][1]=0;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int dist=curr.first;
            int node=curr.second.first;
            int run=curr.second.second;
            if(dist>m[node][run]) continue;
            if(node==n-1) return dist;
            for(auto& it:adj[node]){
                int adjNode=it.first,wt=it.second;
                int newRun=(labels[adjNode]==labels[node])?run+1:1;
                if(newRun>k) continue;
                if(dist+wt<m[adjNode][newRun]){
                    m[adjNode][newRun]=dist+wt;
                    pq.push({dist+wt,{adjNode,newRun}});
                }
            }
        }
        return -1;
    }
};