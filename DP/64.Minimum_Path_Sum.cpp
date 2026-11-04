/*
 * LeetCode: 64 - Minimum Path Sum
 * Link: https://leetcode.com/problems/minimum-path-sum/
 * Difficulty: Medium
 * Time: O(m*n) where m and n are the dimensions of the grid
 * Space: O(m*n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> cost(m,vector<int>(n,INT_MAX));
        cost[0][0]=grid[0][0];
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({grid[0][0],{0,0}});
        vector<int> dx={0,1};
        vector<int> dy={1,0};
        while(!pq.empty()){
            auto [c,corr]=pq.top();
            pq.pop();
            int x=corr.first;
            int y=corr.second;
            for(int i=0;i<2;i++){
                int newX=x+dx[i],newY=y+dy[i];
                if(newX>=m || newY>=n) continue;
                int newCost=c+grid[newX][newY];
                if(cost[newX][newY]<=newCost) continue;
                pq.push({newCost,{newX,newY}});
                cost[newX][newY]=newCost;
            }
        }
        return cost[m-1][n-1];
    }
};