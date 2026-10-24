/*
 * LeetCode: 3310 - Remove Methods From Project
 * Link: https://leetcode.com/problems/remove-methods-from-project/
 * Difficulty: Medium
 * Time: O((V+E)log(V)) in worst case, where V is number of vertices and E is number of edges
 * Space: O(V+E)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto it:invocations) adj[it[0]].push_back(it[1]);
        vector<int> vis(n,0);
        unordered_set<int> u_set;
        queue<int> q;
        q.push(k);
        vis[k]=1;
        while(!q.empty()){
            int node=q.front();q.pop();
            u_set.insert(node);
            for(auto it:adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(auto it:invocations){
            if(u_set.count(it[1])!=0 && u_set.count(it[0])==0){
                u_set.clear();
                break;
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++) if(u_set.count(i)==0) ans.push_back(i);
        return ans;
    }
};