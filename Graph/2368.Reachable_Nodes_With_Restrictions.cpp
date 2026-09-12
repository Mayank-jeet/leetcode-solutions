/*
 * LeetCode: 2368. Reachable Nodes With Restrictions
 * Link: https://leetcode.com/problems/reachable-nodes-with-restrictions/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the graph
 * Space: O(n) for adjecency list, unordered_set and queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for(auto el:edges){
            adj[el[0]].emplace_back(el[1]);
            adj[el[1]].emplace_back(el[0]);
        }
        unordered_set<int> u_set;
        for(int el:restricted) u_set.insert(el);
        queue<pair<int,int>> q;
        q.push({0,-1});
        int ans=1;
        while(!q.empty()){
            pair<int,int> curr=q.front();
            q.pop();
            int currNode=curr.first;
            int parentNode=curr.second;
            for(int i=0;i<adj[currNode].size();i++){
                if(adj[currNode][i]==parentNode || u_set.count(adj[currNode][i])!=0) continue;
                q.push({adj[currNode][i],currNode});
                ans++;
            }
        }
        return ans;
    }
};