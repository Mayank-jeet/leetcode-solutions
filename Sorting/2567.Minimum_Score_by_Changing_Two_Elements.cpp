/*
 * LeetCode: 2567 - Minimum Score by Changing Two Elements
 * Link: https://leetcode.com/problems/minimum-operations-to-sort-with-locked-indices/
 * Difficulty: Medium
 * Time: O(nlog(n)) where n is number of elements in input list
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return min({nums[n-3]-nums[0],nums[n-2]-nums[1],nums[n-1]-nums[2]});
    }
};