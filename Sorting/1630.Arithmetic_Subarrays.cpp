/*
 * LeetCode: 1630 - Arithmetic Subarrays
 * Link: https://leetcode.com/problems/arithmetic-subarrays/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> nums){
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if((nums[i]-nums[i-1])!=(nums[i+1]-nums[i])) return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m=l.size();
        vector<bool> ans;
        for(int i=0;i<m;i++) ans.emplace_back(check(vector<int>(nums.begin()+l[i],nums.begin()+r[i]+1)));
        return ans;
    }
};