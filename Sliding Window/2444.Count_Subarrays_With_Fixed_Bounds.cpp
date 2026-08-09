/*
 * LeetCode: 2444 - Count Subarrays With Fixed Bounds
 * Link: https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
 * Difficulty: Hard
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long ans=0,low=-1,high=-1,exceed=-1,n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) exceed=i;
            if(nums[i]==minK) low=i;
            if(nums[i]==maxK) high=i;
            ans+=max(0L,min(low,high)-exceed);
        }
        return ans;
    }
};