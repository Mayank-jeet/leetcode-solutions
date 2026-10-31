/*
 * LeetCode: 3665 - Twisted Mirror Path Count
 * Link: https://leetcode.com/problems/twisted-mirror-path-count/
 * Difficulty: Medium
 * Time: O(m*n) where m and n are the dimensions of the grid
 * Space: O(m*n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        const int MOD=1e9+7;
        int m=grid.size(),n=grid[0].size();
        long long ans=0;
        vector<vector<long long>> R(m+1,vector<long long>(n+1,0));
        vector<vector<long long>> D(m+1,vector<long long>(n+1,0));
        R[0][0]=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long long r=R[i][j]%MOD,d=D[i][j]%MOD;
                if(grid[i][j]==0){
                    long long w=(r+d)%MOD;
                    if(i==m-1 && j==n-1) ans=(ans+w)%MOD;
                    R[i][j+1]=(R[i][j+1]+w)%MOD;
                    D[i+1][j]=(D[i+1][j]+w)%MOD;
                }
                else{
                    D[i+1][j]=(D[i+1][j]+r)%MOD;
                    R[i][j+1]=(R[i][j+1]+d)%MOD;
                }
            }
        }
        return (int)ans;
    }
};