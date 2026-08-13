/*
 * LeetCode: 2461 - Maximum Sum of Distinct Subarrays With Length K
 * Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
 * Difficulty: Medium
 * Time: O(n) where n is the size of input string
 * Space: O(u) where u is number of unique elements in input array, in worst case it will be O(n), when each element is unique
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0,chunkSum=0;
        unordered_map<int,int> u_map;
        int n=nums.size(),size=0;
        for(int i=0;i<n;i++){
            chunkSum+=nums[i];
            u_map[nums[i]]++;
            if(u_map[nums[i]]==1) size++;
            if(i-k>=0){
                chunkSum-=nums[i-k];
                u_map[nums[i-k]]--;
                if(u_map[nums[i-k]]==0) size--;
            }
            if(size==k) ans=max(ans,chunkSum);
        }
        return ans;
    }
};