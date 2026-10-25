/*
 * LeetCode: 1254 - Number of Closed Islands
 * Link: https://leetcode.com/problems/number-of-closed-islands/
 * Difficulty: Medium
 * Time: O(m·n) where m is number of rows, n is number of columns
 * Space: O(m·n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int sx,int sy){
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        int m=grid.size(),n=grid[0].size();
        bool closed=true;
        queue<pair<int,int>> q;
        q.push({sx,sy});
        vis[sx][sy]=1;
        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            if(x==0||y==0||x==m-1||y==n-1) closed=false;
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx<0||ny<0||nx>=m||ny>=n) continue;
                if(grid[nx][ny]==0&&!vis[nx][ny]){
                    vis[nx][ny]=1;
                    q.push({nx,ny});
                }
            }
        }
        return closed;
    }
    int closedIsland(vector<vector<int>>& grid){
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0&&!vis[i][j]){
                    if(bfs(grid,vis,i,j)) ans++;
                }
            }
        }
        return ans;
    }
};