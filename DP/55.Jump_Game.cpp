/*
 * LeetCode: 55 - Jump Game
 * Link: https://leetcode.com/problems/jump-game/
 * Difficulty: Medium
 * Time: O(n*max(nums)) where n is the length of the input array and max(nums) is the maximum jump length
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        vector<bool> dp(n,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            if(!dp[i]) continue;
            for(int j=1;j<=nums[i];j++){
                if(i+j>=n) break;
                dp[i+j]=true;
            }
            if(dp[n-1]) return true;
        }
        return dp[n-1];
    }
};