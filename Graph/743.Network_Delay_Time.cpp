/*
 * LeetCode: 743 - Network Delay Time
 * Link: https://leetcode.com/problems/network-delay-time/
 * Difficulty: Medium
 * Time: O((V+E)logV) where V is number of vertices and E is nuber of edges
 * Space: O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto el:times) adj[el[0]].emplace_back(el[1],el[2]);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[0]=0;
        dist[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            pair<int,int> curr=pq.top();
            pq.pop();
            int distance=curr.first;
            int node=curr.second;
            for(int i=0;i<adj[node].size();i++){
                int adjNode=adj[node][i].first;
                int newWeight=distance+adj[node][i].second;
                if(newWeight<dist[adjNode]){
                    dist[adjNode]=newWeight;
                    pq.push({newWeight,adjNode});
                }
            }
        }
        int ans=*max_element(dist.begin(),dist.end());
        if(ans==INT_MAX) return -1;
        return ans;
    }
};