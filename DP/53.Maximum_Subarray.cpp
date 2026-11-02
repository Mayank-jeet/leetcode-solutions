/*
 * LeetCode: 53 - Maximum Subarray
 * Link: https://leetcode.com/problems/maximum-subarray/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the input list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int res=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            res=max(res,sum);
            if(sum<0) sum=0;
        }
        return res;
    }
};