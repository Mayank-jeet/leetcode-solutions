/*
 * LeetCode: 2911 - Minimum Changes to Make K Semi-palindromes
 * Link: https://leetcode.com/problems/minimum-changes-to-make-k-semi-palindromes/
 * Difficulty: Hard
 * Time: O(n³log(n)+n²k) where n is the length of the array
 * Space: O(n²+nk)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumChanges(string s,int k){
        int n=s.size(),INF=1e9;
        vector<vector<int>> divs(n+1);
        for(int d=1;d<=n;++d)for(int L=2*d;L<=n;L+=d)divs[L].push_back(d);
        vector<vector<int>> cost(n,vector<int>(n,INF));
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                int L=j-i+1;
                for(int d:divs[L]){
                    int m=L/d,cur=0;
                    for(int r=0;r<d;++r)
                        for(int t=0;t<m/2;++t)
                            cur+=s[i+r+t*d]!=s[i+r+(m-1-t)*d];
                    cost[i][j]=min(cost[i][j],cur);
                }
            }
        }
        vector<vector<int>> dp(n+1,vector<int>(k+1,INF));
        dp[0][0]=0;
        for(int i=1;i<=n;++i)
            for(int p=1;p<=k;++p)
                for(int prev=0;prev<=i-2;++prev)
                    if(dp[prev][p-1]!=INF)
                        dp[i][p]=min(dp[i][p],dp[prev][p-1]+cost[prev][i-1]);
        return dp[n][k];
    }
};