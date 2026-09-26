/*
 * LeetCode: 787 - Cheapest Flights Within K Stops
 * Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * Difficulty: Medium
 * Time: O((E+V)logV) where E is number of edges and V is number of vertices in graph
 * Space: O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto el:flights) adj[el[0]].emplace_back(el[1],el[2]);
        vector<vector<int>> dist(n,vector<int>(k+2,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{src,k+1}});
        dist[src][k+1]=0;
        while(!pq.empty()){
            pair<int,pair<int,int>> curr=pq.top();pq.pop();
            int cost=curr.first;
            int node=curr.second.first;
            int stops=curr.second.second;
            if(node==dst) return cost;
            if(stops==0) continue;
            for(auto el:adj[node]){
                int adjNode=el.first;
                int newCost=el.second+cost;
                if(stops==1 && adjNode!=dst) continue;
                if(newCost<dist[adjNode][stops-1]){
                    dist[adjNode][stops-1]=newCost;
                    pq.push({newCost,{adjNode,stops-1}});
                }
            }
        }
        return -1;
    }
};