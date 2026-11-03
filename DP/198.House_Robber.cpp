/*
 * LeetCode: 198 - House Robber
 * Link: https://leetcode.com/problems/house-robber/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the input vector
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1) take+=dp[i-2];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[n-1];
    }
};