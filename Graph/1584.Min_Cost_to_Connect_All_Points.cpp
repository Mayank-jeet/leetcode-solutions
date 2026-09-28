/*
 * LeetCode: 1584 - Min Cost to Connect All Points
 * Link: https://leetcode.com/problems/min-cost-to-connect-all-points/
 * Difficulty: Medium
 * Time: O(n^2) for forming adj graph, and O(nlog(n)) for traversal, where n is number of points 
 * Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x2=points[j][0],y2=points[j][1];
                adj[i].emplace_back(j,abs(x2-x1)+abs(y2-y1));
            }
        }
        vector<bool> vis(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        int sum=0;
        int visited=0;
        while(visited!=n){
            auto curr=pq.top();
            pq.pop();
            int wt=curr.first;
            int node=curr.second;
            if(vis[node]) continue;
            vis[node]=true;
            sum+=wt;
            visited++;
            for(auto [adjNode,weight]:adj[node]){
                if(!vis[adjNode]) pq.push({weight,adjNode});
            }
        }
        return sum;
    }
};