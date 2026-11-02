/*
 * LeetCode: 462 - Minimum Moves to Equal Array Elements II
 * Link: https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the input array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+n/2,nums.end());
        int med=nums[n/2];
        int ans=0;
        for(int el:nums)ans+=abs(el-med);
        return ans;
    }
};