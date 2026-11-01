/*
 * LeetCode: 4099 - Minimum Operations to Sort With Locked Indices
 * Link: https://leetcode.com/problems/minimum-operations-to-sort-with-locked-indices/
 * Difficulty: Medium
 * Time: O(n^2) where n is number of elements in input list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n=nums.size();
        int unlock=0,maximum=0;
        for(int i=0;i<n;i++){
            maximum=max(maximum,nums[i]);
            if(locked[i]==1 && !(nums[i]==i+1 && maximum==i+1)) unlock++; 
        }
        if(unlock>k) return -1;
        int swaps=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]>nums[j]) swaps++;
            }
        }
        return swaps+unlock;
    }
};