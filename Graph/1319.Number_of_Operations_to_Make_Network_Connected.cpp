/*
 * LeetCode:  1319 - Number of Operations to Make Network Connected
 * Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 * Difficulty: Medium
 * Time: O(n) where n number of vertices in graph
 * Space: O(n) for queue, vis and adj
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n>connections.size()+1) return -1;
        vector<vector<int>> adj(n);
        for(auto el:connections){
            int u=el[0],v=el[1];
            adj[u].emplace_back(v);
            adj[v].emplace_back(u);
        }
        vector<bool> vis(n,false);
        int ext_wire=0,chunk=0;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            chunk++;
            queue<pair<int,int>> q;
            q.push({i,i});
            vis[i]=true;
            while(!q.empty()){
                int index=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto el:adj[index]){
                    if(!vis[el]){
                        vis[el]=true;
                        q.push({el,index});
                    }
                    else if(el!=parent) ext_wire++;
                }
            }
        }
        if(((ext_wire/2)<(chunk-1))) return -1;
        return chunk-1;
    }
};