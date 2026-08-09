/*
 * LeetCode: 713 - Subarray Product Less Than K
 * Link: https://leetcode.com/problems/subarray-product-less-than-k/
 * Difficulty: Medium
 * Time: O(n) for the sliding window approach
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k<=1) return 0;
        long long prod=1;
        int j=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            while(prod>=k){
                prod/=nums[j];
                j++;
            }
            ans+=(i+1-j);
        }
        return ans;
    }
};