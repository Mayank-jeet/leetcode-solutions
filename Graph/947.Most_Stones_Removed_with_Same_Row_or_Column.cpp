/*
 * LeetCode: 947 - Most Stones Removed with Same Row or Column
 * Link: https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
 * Difficulty: Medium
 * Time: O(n·α(n))
 * Space: O(maxRow+maxCol)
 */
#include <bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> parent,rank;
public:
    DisjointSet(int n){
        parent.resize(n);
        rank.assign(n, 0);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    int findUParent(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUParent(parent[node]);
    }
    void unionByRank(int u,int v){
        int u_par=findUParent(u);
        int v_par=findUParent(v);
        if(u_par==v_par) return;
        if(rank[u_par]<rank[v_par]) parent[u_par]=v_par;
        else if(rank[v_par]<rank[u_par]) parent[v_par]=u_par;
        else{
            parent[v_par]=u_par;
            rank[u_par]++;
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxRow=0,maxCol=0;
        for (auto &s:stones) {
            maxRow=max(maxRow,s[0]);
            maxCol=max(maxCol,s[1]);
        }
        DisjointSet ds(maxRow+maxCol+2);
        for(auto &node:stones) ds.unionByRank(node[0],node[1]+maxRow+1);
        unordered_set<int> used;
        for (auto &s:stones) {
            int r=s[0];
            int c=s[1]+maxRow+1;
            ds.unionByRank(r,c);
            used.insert(r);
            used.insert(c);
        }
        unordered_set<int> roots;
        for (int node:used) roots.insert(ds.findUParent(node));
        return stones.size()-roots.size();
    }
};