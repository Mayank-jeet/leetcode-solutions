/*
 * LeetCode: 2640 - Find the Score of All Prefixes of an Array
 * Link: https://leetcode.com/problems/find-the-score-of-all-prefixes-of-an-array/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(n) considering the output array, otherwise O(1)
 */ 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans;
        int maxi=INT_MIN,n=nums.size();
        long long convSum=0;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
            convSum+=(maxi+nums[i]);
            ans.push_back(convSum);
        }
        return ans;
    }
};