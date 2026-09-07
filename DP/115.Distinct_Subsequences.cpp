/*
 * LeetCode: 115 - Distinct Subsequences
 * Link: https://leetcode.com/problems/distinct-subsequences/
 * Difficulty: Hard
 * Time: O(n*m) where n is the length of t and m is the length of s
 * Space: O(n*m)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        int m=s.length(),n=t.length();
        if(n>m) return 0;
        vector<vector<unsigned  long long>> dp(m+1,vector<unsigned long long>(n+1));
        for(int i=0;i<=m;i++) dp[i][n]=1;
        for(int i=m-1;i>=0;i--){
            char sChar=s[i];
            for(int j=n-1;j>=0;j--){
                if(t[j]==sChar) dp[i][j]=dp[i+1][j]+dp[i+1][j+1];
                else dp[i][j]=dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};