/*
 * LeetCode: 1042 - Flower Planting With No Adjacent
 * Link: https://leetcode.com/problems/flower-planting-with-no-adjacent/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for(auto node:paths){
            adj[node[0]-1].emplace_back(node[1]-1);
            adj[node[1]-1].emplace_back(node[0]-1);
        }
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            vector<int> color(5,0);
            for(int j=0;j<adj[i].size();j++) color[ans[adj[i][j]]]=1;
            for(int k=4;k>0;k--) if(color[k]==0) ans[i]=k;
        }
        return ans;
    }
};