/*
 * LeetCode: 1514 - Path with Maximum Probability
 * Link: https://leetcode.com/problems/find-champion-ii/
 * Difficulty: Medium
 * Time: O((V+E)log(V)) where V is number of vertices and E is number of edges
 * Space: O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].emplace_back(edges[i][1],succProb[i]);
            adj[edges[i][1]].emplace_back(edges[i][0],succProb[i]);
        }
        vector<double> prob(n,0);
        prob[start_node]=1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            pair<double,int> curr=pq.top();pq.pop();
            double currProb=curr.first;
            int node=curr.second;
            for(int i=0;i<adj[node].size();i++){
                int adjNode=adj[node][i].first;
                double adjNodeProb=adj[node][i].second;
                double newProb=currProb*adjNodeProb;
                if(prob[adjNode]<newProb){
                    prob[adjNode]=newProb;
                    pq.push({newProb,adjNode});
                }
            }
        }
        return prob[end_node];
    }
};