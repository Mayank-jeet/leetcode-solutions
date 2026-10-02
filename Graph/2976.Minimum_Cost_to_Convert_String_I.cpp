/*
 * LeetCode: 2976 - Minimum Cost to Convert String I
 * Link: https://leetcode.com/problems/minimum-cost-to-convert-string-i/
 * Difficulty: Medium
 * Time: O(m+26^3+L) where m is size of original/changed/cost vector ans L is size of source/target string
 * Space: O(26^2) for dist vector
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const long long INF=LLONG_MAX/4;
        vector<vector<long long>> dist(26,vector<long long>(26,INF));
        for(int i=0;i<26;i++) dist[i][i]=0;
        for(int i=0;i<original.size();i++){
            int u=original[i]-'a',v=changed[i]-'a';
            if(u==v) continue;
            dist[u][v]=min(dist[u][v],(long long)cost[i]);
        }
        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k]==INF || dist[k][j]==INF) continue;
                    dist[i][j]=min(dist[i][k]+dist[k][j],dist[i][j]);
                }
            }
        }
        long long ans=0;
        for(int i=0;i<source.size();i++){
            int u=source[i]-'a',v=target[i]-'a';
            if(dist[u][v]==INF) return -1;
            ans+=dist[u][v];
        }
        return ans;
    }
};