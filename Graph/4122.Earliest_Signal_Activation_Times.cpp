/*
 * LeetCode: 4122 - Earliest Signal Activation Times
 * Link: https://leetcode.com/problems/earliest-signal-activation-times/
 * Difficulty: Medium
 * Time: O((E+V)logV) where E is number of edges and V is number of vertices in graph
 * Space: O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> earliestActivationTimes(int n, vector<vector<int>>& edges, vector<int>& requiredSignals) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto it:edges) adj[it[0]].emplace_back(it[1],it[2]);
        vector<long long> ans(n,-1);
        vector<int> req=requiredSignals;
        req[0]=0;
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        while(!pq.empty()){
            auto [time,node]=pq.top();pq.pop();
            if(ans[node]!=-1) continue;
            if(--req[node]>0) continue;
            ans[node]=time;
            for(auto [adjNode,adjTime]:adj[node]){
                if(ans[adjNode]==-1) pq.push({time+adjTime,adjNode});
            }
        }
        return ans;
    }
};