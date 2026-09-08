/*
 * LeetCode:  2477 - Minimum Fuel Cost to Report to the Capital
 * Link: https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital/
 * Difficulty: Medium
 * Time: O(E+V) where E is number of edges and V is number of vertices
 * Space: O(V)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long ans=0;
    int dfs(vector<vector<int>>& adj,int prev,int index,int& seats){
        int passangers=1;
        int n=adj[index].size();
        for(int i=0;i<n;i++){
            if(adj[index][i]==prev) continue;
            passangers+=dfs(adj,index,adj[index][i],seats);
        }
        if(index>0) ans+=(passangers+seats-1)/seats;
        return passangers;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n=roads.size()+1;
        vector<vector<int>> adj(n+1);
        for(auto el:roads){
            adj[el[0]].emplace_back(el[1]);
            adj[el[1]].emplace_back(el[0]);
        }
        dfs(adj,-1,0,seats);
        return ans;
    }
};