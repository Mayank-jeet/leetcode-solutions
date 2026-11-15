/*
 * LeetCode: 4112 - Maximize Score After Zeroing Subtrees
 * Link: https://leetcode.com/problems/maximize-score-after-zeroing-subtrees/
 * Difficulty: Medium
 * Time: O((V+E)log(V)) where V is number of vertices and E is number of edges
 * Space: O(V+E) for reciursion stack and adjacency list
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long dfs(vector<vector<int>>& adj, vector<int>& op, vector<int>& score, int src){
        long long sum=score[src];
        if(adj[src].size()==0) return sum;
        long long mn=LLONG_MAX;
        for(int el:adj[src]){
            long long temp=dfs(adj,op,score,el);
            sum+=temp;
            mn=min(mn,temp);
        }
        if(op[src]==1||mn<0) sum-=mn;
        return sum;
    }
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n=parent.size();
        vector<vector<int>> adj(n);
        for(int i=1;i<n;i++) adj[parent[i]].push_back(i);
        return (int)dfs(adj,op,score,0);
    }
};