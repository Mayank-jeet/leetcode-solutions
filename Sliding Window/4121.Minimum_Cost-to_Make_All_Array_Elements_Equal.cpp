/*
 * LeetCode: 4121 - Minimum Cost to Make All Array Elements Equal
 * Link: https://leetcode.com/problems/minimum-cost-to-make-all-array-elements-equal/
 * Difficulty: Medium
 * Time: O(n) where n is the length of the input array
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minCost(vector<int>& nums) {
        int n=nums.size();
        if(n<3) return 0;
        long long ans=LLONG_MAX;
        int i=0;
        while(i<n){
            int j=i;
            while(j+1<n && nums[j+1]==nums[i]) j++;
            if(j>=1 && i<=n-2) ans=min(ans,(long long)nums[i]*(i+n-1-j));
            i=j+1;
        }
        return ans;
    }
};