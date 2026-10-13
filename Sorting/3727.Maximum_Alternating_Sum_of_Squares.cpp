/*
 * LeetCode: 3727 - Maximum Alternating Sum of Squares
 * Link: https://leetcode.com/problems/maximum-alternating-sum-of-squares/
 * Difficulty: Medium
 * Time: O(nlog(n)) where n is number of elements in input vector
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++) if(nums[i]<0) nums[i]*=-1;
        sort(nums.begin(),nums.end(),greater<>());
        long long ans=0;
        for(int i=0;i<n/2;i++) ans+=(nums[i]*nums[i]-nums[n-1-i]*nums[n-1-i]);
        if(n%2!=0) ans+=nums[n/2]*nums[n/2];
        return ans;
    }
};