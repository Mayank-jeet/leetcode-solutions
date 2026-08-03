/*
 * LeetCode: 974 - Subarray Sums Divisible by K
 * Link: https://leetcode.com/problems/subarray-sums-divisible-by-k/
 * Difficulty: Medium
 * Time: O(n) wwhere n size of the input vector
 * Space: O(n) space used for unordered_map
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> u_map={{0,1}};
        int ans=0,n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0) rem+=k;
            ans+=u_map[rem];
            u_map[rem]++;
        }
        return ans;
    }
};