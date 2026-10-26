/*
 * LeetCode: 3619 - Count Islands With Total Value Divisible by K
 * Link: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
 * Difficulty: Medium
 * Time: O(m·n) where m is number of rows and n is number of columns
 * Space: O(m·n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int x,int y){
        vector<int> dx={0,0,1,-1};
        vector<int> dy={1,-1,0,0};
        queue<pair<int,int>> q;
        q.push({x,y});
        vis[x][y]=1;
        long long sum=grid[x][y];
        int m=grid.size(),n=grid[0].size();
        while(!q.empty()){
            auto [xCorr,yCorr]=q.front();q.pop();
            for(int i=0;i<4;i++){
                int newX=xCorr+dx[i],newY=yCorr+dy[i];
                if(newX<0 || newY<0 || newX>=m || newY>=n || vis[newX][newY] || grid[newX][newY]==0) continue;
                vis[newX][newY]=1;
                sum+=(long long)grid[newX][newY];
                q.push({newX,newY});
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]!=0 && !vis[i][j]){
                    long long sum=bfs(grid,vis,i,j);
                    if(sum%k==0) ans++;
                } 
            }
        }
        return ans;
    }
};