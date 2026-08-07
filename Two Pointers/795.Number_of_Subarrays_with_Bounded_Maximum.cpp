/*
 * LeetCode: 795 - Number of Subarrays with Bounded Maximum
 * Link: https://leetcode.com/problems/number-of-subarrays-with-bounded-maximum/
 * Difficulty: Medium
 * Time: O(n)
 * Space: O(1)
 */
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int low=0,high=0,n=nums.size(),ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]>right){
                low=i+1;
                high=i+1;
                continue;
            }
            else if(nums[i]>=left) high=i; 
            if(low==high){
                if(low<n && nums[low]>=left && nums[low]<=right) ans++;
            }
            else ans+=(high-low+1);
        }
        return ans;
    }
};