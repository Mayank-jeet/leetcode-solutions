/*
 * LeetCode: 62 - Unique Paths
 * Link: https://leetcode.com/problems/unique-paths/
 * Difficulty: Medium
 * Time: O(m*n)
 * Space: O(m*n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<long long>> R(m+1,vector<long long>(n+1,0));
        vector<vector<long long>> D(m+1,vector<long long>(n+1,0));
        R[0][0]=1;
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                long long r=R[i][j],d=D[i][j];
                long long w=(r+d);
                if(i==m-1 && j==n-1) ans=(ans+w);
                R[i][j+1]=(R[i][j+1]+w);
                D[i+1][j]=(D[i+1][j]+w);
            }
        }
        return ans;
    }
};