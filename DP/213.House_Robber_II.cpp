/*
 * LeetCode: 213 - House Robber II
 * Link: https://leetcode.com/problems/house-robber-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the input list
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int  find(vector<int>& arr,int l,int r){
        int n=arr.size();
        vector<int> dp(n,0);
        dp[l]=arr[l];
        for(int i=l+1;i<r;i++){
            int take=arr[i];
            if (i>l+1) take+=dp[i-2];
            int notTake=dp[i-1];
            dp[i]=max(take,notTake);
        }
        return dp[r-1];
    }
    int rob(vector<int>& nums) {
        int m=nums.size();
        if (m==1) return nums[0];
        return max(find(nums,0,m-1),find(nums,1,m));
    }
};