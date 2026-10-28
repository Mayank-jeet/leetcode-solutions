/*
 * LeetCode: 3882 - Minimum XOR Path in a Grid
 * Link: https://leetcode.com/problems/minimum-xor-path-in-a-grid/
 * Difficulty: Hard
 * Time: O(m*n*V) where m and n are the dimensions of the grid and V is the number of possible XOR values
 * Space: O(m*n*V)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<unordered_set<int>>> dp(m,vector<unordered_set<int>>(n));
        dp[0][0].insert(grid[0][0]);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0&&j==0) continue;
                int v=grid[i][j];
                if(i>0) for(int x:dp[i-1][j]) dp[i][j].insert(x^v);
                if(j>0) for(int x:dp[i][j-1]) dp[i][j].insert(x^v);
            }
        }
        return *min_element(dp[m-1][n-1].begin(),dp[m-1][n-1].end());
    }
};