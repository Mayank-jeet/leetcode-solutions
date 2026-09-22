/*
 * LeetCode: 1334 - Find the City With the Smallest Number of Neighbors at a Threshold Distance3568 - Minimum Moves to Clean the Classroom
 * Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
 * Difficulty: Medium
 * Time: O(n^3)
 * Space: O(n^2)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n,vector<int>(n,INT_MAX));
        for(auto edge:edges){
            cost[edge[0]][edge[1]]=edge[2];
            cost[edge[1]][edge[0]]=edge[2];
        }
        for(int i=0;i<n;i++) cost[i][i]=0;
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(cost[i][k]==INT_MAX || cost[k][j]==INT_MAX) continue;
                    cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
                }
            }
        }
        int minCount=INT_MAX,ans=-1;
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(cost[i][j]<=distanceThreshold) count++;
            }
            if(count<=minCount){
                minCount=count;
                ans=i;
            }
        }
        return ans;
    }
};