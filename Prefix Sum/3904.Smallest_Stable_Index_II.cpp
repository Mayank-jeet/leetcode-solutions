/*
 * LeetCode: 3904 - Smallest Stable Index II
 * Link: https://leetcode.com/problems/smallest-stable-index-ii/
 * Difficulty: Medium
 * Time: O(n) 
 * Space: O(n)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> minVec;
        int n=nums.size();
        int maxEl=INT_MIN,minEl=INT_MAX;
        for(int i=n-1;i>=0;i--){
            minEl=min(minEl,nums[i]);
            minVec.emplace_back(minEl);
        }
        for(int i=0;i<n;i++){
            maxEl=max(nums[i],maxEl);
            if((maxEl-minVec[n-1-i])<=k) return i;
        }
        return -1;
    }
};