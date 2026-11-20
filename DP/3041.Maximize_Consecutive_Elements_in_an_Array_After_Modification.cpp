/*
 * LeetCode: 3041 - Maximize Consecutive Elements in an Array After Modification
 * Link: https://leetcode.com/problems/maximize-consecutive-elements-in-an-array-after-modification/
 * Difficulty: Hard
 * Time: O(n) where n is the length of the array
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        unordered_map<int, int> dp;
        int ans=0;
        for (int num:nums){
            dp[num+1]=dp[num]+1;
            dp[num]=dp[num-1]+1;
            ans=max({ans,dp[num],dp[num+1]});
        }
        return ans;
    }
};