/*
 * LeetCode: 210 - Course Schedule II
 * Link: https://leetcode.com/course-schedule-ii/
 * Difficulty: Medium
 * Time: O(V+E) where V is number of vertices and E is number of edges
 * Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].emplace_back(prerequisites[i][0]);
        }
        vector<int> inqueue(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(int j=0;j<adj[i].size();j++){
                inqueue[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(inqueue[i]==0) q.push(i);
        }
        vector<int> topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                inqueue[adj[node][i]]--;
                if(inqueue[adj[node][i]]==0) q.push(adj[node][i]);
            }
        }
        if (topo.size()==numCourses) return topo;
        return {};
    }
};