/*
 * LeetCode: 3558 - Number of Ways to Assign Edge Weights I
 * Link: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
 * Difficulty: Medium
 * Time: O(n) where n is the number of nodes in the tree
 * Space: O(n) space used for adjacency list,visited array and queue
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long power(long long base, long long exp, long long mod) {
        long long result = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;
        }
        return result;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto el:edges){
            int u=el[0],v=el[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        queue<int> q;
        q.push(1);
        q.push(-1);
        int depth=-1;
        vector<bool> vis(n+1,false);
        vis[1]=true;
        while(!q.empty()){
            int index=q.front();
            q.pop();
            if(index==-1){
                depth++;
                if(!q.empty()) q.push(-1);
            }
            else{
                for(auto el:adj[index]){
                    if(!vis[el]){
                        q.push(el);
                        vis[el]=true;
                    }
                }
            }
        }
        long long mod = 1e9 + 7;
        return (int)power(2, depth - 1, mod);
    }
};