/*
 * LeetCode: 2134 - Minimum Swaps to Group All 1's Together II
 * Link: https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones=0,n=nums.size(),chunk=0;
        for(int el:nums) if(el==1) ones++;
        for(int i=0;i<ones;i++) if(nums[i]==0) chunk++;
        int ans=chunk;
        for(int i=1;i<n;i++){
            if(nums[i-1]==0 && nums[ones%n]==1) chunk--;
            else if(nums[i-1]==1 && nums[ones%n]==0) chunk++;
            if(chunk<ans) ans=chunk;
            ones++;
        }
        return ans;
    }
};