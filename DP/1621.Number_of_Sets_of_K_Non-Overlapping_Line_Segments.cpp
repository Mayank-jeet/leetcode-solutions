/*
 * LeetCode: 1621 - Number of Sets of K Non-Overlapping Line Segments
 * Link: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
 * Difficulty: Medium
 * Time: O(n*k)
 * Space: O(n*k)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    const long long MOD=1000000007;
    int numberOfSets(int n, int k) {
        vector<vector<long long>> dp(n, vector<long long>(k + 1));
        for(int i=0;i<n;i++) dp[i][0]=1;
        for(int j=1;j<=k;j++){
            long long sum=0;
            for(int i=1;i<n;i++){
                sum=(sum+dp[i-1][j-1])%MOD;
                dp[i][j]=(dp[i-1][j]+sum)%MOD;
            }
        }
        return dp[n-1][k];
    }
};