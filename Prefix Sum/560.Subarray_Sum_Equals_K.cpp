/*
 * LeetCode: 560 - Subarray Sum Equals K
 * Link: https://leetcode.com/problems/subarray-sum-equals-k/
 * Difficulty: Medium
 * Time: O(n) where n size of the input vector
 * Space: O(n) space used by the unordered_map
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> u_map={{0,1}};
        int n=nums.size(),ans=0,sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            ans+=u_map[sum-k];
            u_map[sum]++;
        }
        return ans;
    }
};