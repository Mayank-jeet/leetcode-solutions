/*
 * LeetCode: 3974 - Maximum Total Sum of K Selected Elements
 * Link: https://leetcode.com/problems/maximum-total-sum-of-k-selected-elements/
 * Difficulty: Medium
 * Time: O(nlogn)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        long long ans=0;
        for(int i=n-1;i>(n-1-k);i--){
            if(mul>1){
                ans+=((long long)mul*nums[i]);
                mul--;
            }else ans+=nums[i];
        }
        return ans;
    }
};