/*
 * LeetCode: 45 - Jump Game II
 * Link: https://leetcode.com/problems/jump-game-ii/
 * Difficulty: Medium
 * Time: O(n*max(nums)) where n is the length of the input array and max(nums) is the maximum jump length
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=nums[i];j++){
                if(i+j>=n) break;
                dp[i+j]=min(dp[i+j],dp[i]+1);
            }
            if(dp[n-1]!=INT_MAX) return dp[n-1];
        }
        return dp[n-1];
    }
};