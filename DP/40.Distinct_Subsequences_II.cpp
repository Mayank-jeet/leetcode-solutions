/*
 * LeetCode: 40 - Distinct Subsequences II
 * Link: https://leetcode.com/problems/distinct-subsequences-ii/
 * Difficulty: Hard
 * Time: O(n) where n is the length of input string s
 * Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int MOD=1e9+7;
    int distinctSubseqII(string s) {
        int tot=0,dp[26]{};
        for (auto&c:s){
            c-='a';
            int add=(tot-dp[c]+MOD)%MOD;
            dp[c]=1+tot;
            tot=(dp[c]+add)%MOD;
        }
        return tot;
    }
};