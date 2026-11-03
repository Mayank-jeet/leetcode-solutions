/*
 * LeetCode: 63 - Unique Paths II
 * Link: https://leetcode.com/problems/unique-paths-ii/
 * Difficulty: Medium
 * Time: O(m*n) where m and n are the dimensions of the input grid
 * Space: O(m*n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 || obstacleGrid[m-1][n-1]==1) return 0;
        int ans=0;
        vector<vector<int>> R(m+1,vector<int>(n+1,0));
        vector<vector<int>> D(m+1,vector<int>(n+1,0));
        R[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int r=R[i][j],d=D[i][j];
                if(obstacleGrid[i][j]==0){
                    int w=r+d;
                    if(i==m-1 && j==n-1) ans+=w;
                    R[i][j+1]=(R[i][j+1]+w);
                    D[i+1][j]=(D[i+1][j]+w);
                }
            }
        }
        return ans;
    }
};